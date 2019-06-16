import java.io.IOException;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.DoubleWritable;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.GenericOptionsParser;

public class stuGrade {
	
	public static class TokenizerMapper extends Mapper<Object, Text, Text, IntWritable>{
		
		public void map(Object key, Text value, Context context) throws IOException, InterruptedException{
			
			StringTokenizer st=new StringTokenizer(value.toString());
			
			while(st.hasMoreTokens()) {
				String nextToken=st.nextToken();
				String att[]=nextToken.toString().split(",");
				
				if(att[3].equals("±ØÐÞ")==true) {
					context.write(new Text(att[0]+","+att[1]), new IntWritable(Integer.parseInt(att[4])));
				}
			}
			
		}
	}
	
	public static class IntSumReducer extends Reducer<Text, IntWritable, Text, DoubleWritable>{
		
		public void reduce(Text key, Iterable<IntWritable> values, Context context) throws IOException, InterruptedException {
			
			int sum=0, num=0;
			
			for(IntWritable val : values) {
				sum+=val.get();
				num++;
			}
			context.write(key, new DoubleWritable(sum*1.0/num));
		}
	}

	public static void main(String args[]) throws IOException, ClassNotFoundException, InterruptedException {
		Configuration conf=new Configuration();
		String[] otherArgs = new GenericOptionsParser(conf, args).getRemainingArgs();
		if (otherArgs.length < 2) {
			System.err.println("Usage: GradeSTA1 <in> [<in>...] <out>");
			System.exit(2);
		}
		
		Job job=Job.getInstance(conf, "stuGrade");
		job.setJarByClass(stuGrade .class);
		job.setMapperClass(TokenizerMapper.class);
		job.setReducerClass(IntSumReducer.class);
		
		job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(IntWritable.class);
		job.setOutputKeyClass(Text.class);
		job.setOutputValueClass(DoubleWritable.class);
		
		for (int i = 0; i < otherArgs.length - 1; ++i) {
			FileInputFormat.addInputPath(job, new Path(otherArgs[i]));
		}
		FileOutputFormat.setOutputPath(job, new Path(otherArgs[otherArgs.length - 1]));
		
		System.exit(job.waitForCompletion(true) ? 0 : 1);
	}
	
}
