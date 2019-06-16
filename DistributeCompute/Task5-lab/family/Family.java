import java.io.IOException;
import java.util.StringTokenizer;

import java.util.ArrayList;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;

public class Family {
 
	public static class MyMapper extends Mapper<Object, Text, Text, Text> {
 
		public void map(Object key, Text value, Context context)
				throws IOException, InterruptedException {
			String child = value.toString().split(",")[0];
			String parent = value.toString().split(",")[1];
			
			context.write(new Text(child), new Text("-" + parent));
			context.write(new Text(parent), new Text("+" + child));
		}
	}
 
	public static class MyReducer extends Reducer<Text, Text, Text, Text> {
 
		public void reduce(Text key, Iterable<Text> values, Context context)
				throws IOException, InterruptedException {
			ArrayList<Text> grandparent = new ArrayList<Text>();
			ArrayList<Text> grandchild = new ArrayList<Text>();
			for (Text t : values) {
				String s = t.toString();
				if (s.startsWith("-")) {
					grandparent.add(new Text(s.substring(1)));
				} else {
					grandchild.add(new Text(s.substring(1)));
				}
			}
			for (int i = 0; i < grandchild.size(); i++) {
				for (int j = 0; j < grandparent.size(); j++) {
					context.write(grandchild.get(i), grandparent.get(j));
				}
			}
		}
	}
 
	public static void main(String[] args) throws Exception {
		Configuration conf = new Configuration();
 
		String[] otherArgs = new GenericOptionsParser(conf, args)
				.getRemainingArgs();
		if (otherArgs.length != 2) {
			System.err.println("Usage: wordcount <in> <out>");
			System.exit(2);
		}
		Job job = new Job(conf,"family");
		job.setJarByClass(Family.class);
		job.setMapperClass(MyMapper.class);
		job.setReducerClass(MyReducer.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
 
		Path path = new Path(otherArgs[1]);
		
 
		FileInputFormat.addInputPath(job, new Path(otherArgs[0]));
		FileOutputFormat.setOutputPath(job, new Path(otherArgs[1]));
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}	
 
}