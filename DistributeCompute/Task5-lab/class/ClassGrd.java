import java.io.IOException;
import java.util.StringTokenizer;

import java.util.ArrayList;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;

public class ClassGrd {
 
	public static class MyMapper extends Mapper<Object, Text, Text, Text> {
		Text kout = new Text();
		Text vout = new Text();
		
		public void map(Object key, Text value, Context context)
				throws IOException, InterruptedException {
			String [] reads = value.toString().trim().split(",");
				String kk = reads[2]+reads[0];
				String vv = reads[4];
				kout.set(kk);
				vout.set(vv);
				context.write(kout, vout);
			
		}
	}
 
	public static class MyReducer extends Reducer<Text, Text, Text, Text> {
		Text kout = new Text();
		Text vout = new Text();
		public void reduce(Text key, Iterable<Text> values, Context context)
				throws IOException, InterruptedException {
			int sum= 0;
			int count= 0;
			double avgscore = 0;
			for(Text text : values){
				int score = Integer.parseInt(text.toString());
				
				sum += score;
				count++;
			}
			avgscore = sum*1.0/ count;
			String vv = "avg="+avgscore;
			vout.set(vv);
			context.write(key, vout);
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
		Job job = new Job(conf,"Student score");
		job.setJarByClass(ClassGrd.class);
		job.setMapperClass(MyMapper.class);
		job.setReducerClass(MyReducer.class);
		
		job.setMapOutputKeyClass(Text.class);
		job.setMapOutputValueClass(Text.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(Text.class);
 
		Path path = new Path(otherArgs[1]);
		
 
		FileInputFormat.addInputPath(job, new Path(otherArgs[0]));
		FileOutputFormat.setOutputPath(job, new Path(otherArgs[1]));
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}	
 
}