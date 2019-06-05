package com.onezeros.touchpad;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.util.Printer;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.View.OnTouchListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.Toast;

public class TouchPadActivity extends Activity {
	private static final String TAG = "lzhj"; 
	RelativeLayout mTouchpadLayout;
    ImageView mMouseLeftImageView;
    ImageView mMouseRightImageView;
    ImageView mMouseMiddleImageView;
    FrameLayout mTouchpaneLayout;
    
    
    LinearLayout mSetupLayout;
    EditText mServerIPEditText;
    EditText mServerPortText;
    Button mConnectButton;
    
    Socket mSocket;
    PrintWriter mWriter;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        mTouchpadLayout = (RelativeLayout)findViewById(R.id.touchpad_layout);
        mMouseLeftImageView = (ImageView)findViewById(R.id.mouse_left);
        mMouseMiddleImageView = (ImageView)findViewById(R.id.mouse_middle_btn);
        mMouseRightImageView = (ImageView)findViewById(R.id.mouse_right);
        mTouchpaneLayout = (FrameLayout)findViewById(R.id.touch_panel);
        
        mSetupLayout = (LinearLayout)findViewById(R.id.setup_ll);
        mServerIPEditText = (EditText)findViewById(R.id.serverip_et);
        mServerPortText = (EditText)findViewById(R.id.port_et);
        mConnectButton = (Button)findViewById(R.id.connect_bt);
        
        mConnectButton.setOnClickListener(new OnClickListener() {
			
			@Override
			//单击函数
			public void onClick(View v) {
				try {
					Log.d(TAG, "stub 1 ");//记录日志语句，不是重点
					
					
					
					//建立socket连接，这个是重点
					//java中建立socket连接的语句就是 Socket s=new socket（ip地址，端口号），其中ip地址是String类型，端口号是int型。
					//mServerIPEditText.getText().toString()这个是根据界面中id为mServerIPEditText的输入框元素的内容获得ip地址并转化为字符串
					//Integer.parseInt(mServerPortText.getText().toString()根据界面中id为mServerPortText的输入框元素内容获得端口号，端口号是int型所以转化为int。Integer函数就是这个功能
					mSocket = new Socket(mServerIPEditText.getText().toString(), Integer.parseInt(mServerPortText.getText().toString()));
					
					
					
					Log.d(TAG, "stub 2 ");
					
					
					//定义一个输出流，将信息全部加载到输出流中发送给服务器。这些是利用已经建立连接的mSocket
					mWriter = new PrintWriter(new BufferedWriter(new OutputStreamWriter(mSocket.getOutputStream())));
					Log.d(TAG, "stub 3 ");
					
					if (mSocket.isConnected()) {		
						//如果连接成功，显示mTouchpadLayout这个层。将原来的层覆盖住。就是鼠标面板这个
						mTouchpadLayout.setVisibility(View.VISIBLE);
					}
					Log.d(TAG,"mSocket.isConnected() = "+mSocket.isConnected());
					
				} catch (NumberFormatException e) {
					e.printStackTrace();
				} catch (UnknownHostException e) {
					e.printStackTrace();
				} catch (IOException e) {
					e.printStackTrace();
				}
				
				
			}
		});
        
        
        //点击屏幕中的“鼠标左键”动作
        mMouseLeftImageView.setOnTouchListener(new OnTouchListener() {
			
			@Override
			public boolean onTouch(View v, MotionEvent event) {
				
				String action = null ;
				//监听动作类型
				switch (event.getAction()) {
				
				//如果动作类型是点下
				case MotionEvent.ACTION_DOWN:
					//将action这个字符串赋值为MOUSEEVENTF_LEFTDOWN
					action = "MOUSEEVENTF_LEFTDOWN";
					break;
					
					
					//如果动作类型是离开
				case MotionEvent.ACTION_UP:
					//将action这个字符串赋值为MOUSEEVENTF_LEFTUP
					action = "MOUSEEVENTF_LEFTUP";
					break;
				default:
					break;
				}
				//如果action祖父传不为空
				if (action != null) {
					//调用sendSocketMessage函数，将action这个字符串发给服务器
					sendSocketMessage(action);
				}
				return true;
			}
		});
        
        
        //点击屏幕中的“鼠标右键”动作
        mMouseRightImageView.setOnTouchListener(new OnTouchListener() {
			
			@Override
			public boolean onTouch(View v, MotionEvent event) {
				String action = null ;
				switch (event.getAction()) {
				case MotionEvent.ACTION_DOWN:
					action = "MOUSEEVENTF_RIGHTDOWN";
					break;
				case MotionEvent.ACTION_UP:
					action = "MOUSEEVENTF_RIGHTUP";
					break;
				default:
					break;
				}
				if (action != null) {
					sendSocketMessage(action);
				}
				return true;
			}
		});
        
        
        //点击屏幕中的“鼠标滚轮”动作
        mMouseMiddleImageView.setOnTouchListener(new OnTouchListener() {
			
			@Override
			public boolean onTouch(View v, MotionEvent event) {
				String action = null ;
				switch (event.getAction()) {
				case MotionEvent.ACTION_DOWN:
					action = "MOUSEEVENTF_MIDDLEDOWN";
					break;
				case MotionEvent.ACTION_MOVE:
					break;
				case MotionEvent.ACTION_UP:
					action = "MOUSEEVENTF_MIDDLEUP";
					break;
				default:
					break;
				}
				if (action != null) {
					sendSocketMessage(action);
				}
				return true;
			}
		});
        
        
        //鼠标面板滑动动作，就是在这个区域内滑动所要产生的信息处理
        mTouchpaneLayout.setOnTouchListener(new OnTouchListener() {
        	//对位置坐标的定义
			float lastX;
			float lastY;
			@Override
			public boolean onTouch(View v, MotionEvent event) {//当点击面板时
				String actionString = null;
				//检测用户动作
				switch (event.getAction()) {
				
				//如果动作类型是点下
				case MotionEvent.ACTION_DOWN:
					//actionString = String.format("DOWN:(%f,%f)", event.getX(),event.getY());
					//记录当前点下的位置坐标
					lastX = event.getX();
					lastY = event.getY();
					break;
					
					
					
					//如果动作是在屏幕上移动
				case MotionEvent.ACTION_MOVE:
					
					//actionString字符串记录下来的就是终点坐标减去起点坐标，这个记录的频率好像跟系统定义有关，并且对这个信息格式化一下，有利于服务器接收数据之后操作。
					//String.format就是个格式化函数，格式化的形势类似MOUSEEVENTF_MOVE %f %f
					actionString = String.format("MOUSEEVENTF_MOVE %f %f", event.getX() - lastX,event.getY() - lastY);
					lastX = event.getX();
					lastY = event.getY();
							
					break;
					
					//如果动作是用户从屏幕离开
				case MotionEvent.ACTION_UP:
					//actionString = String.format("UP:(%f,%f)", event.getX(),event.getY());
					break;

				default:
					break;
				}
				if (actionString!= null) {
					sendSocketMessage(actionString);
				}
				return true;
			}
		});
    }
    
    //与服务器断开连接的动作
    public void stopConnection() {
    	if(mSocket.isConnected()){
    		try {
    			//先关闭流
    			mWriter.close();
				//在关闭socket
    			mSocket.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
    		
    	}
    }
    
    
    //给服务器发送消息的函数，这个函数就是利用到socket建立连接之后采用输出流的方式将信息发送给服务器、也就是前面定义的mWriter这个
    
    public void sendSocketMessage(String message) {
    	//如果前面socket连接不成功
    	if (!mSocket.isConnected()) {
    		//toast是一个通知框，就是在当前页面显示一个连接不成功的通知。
			Toast.makeText(this, "connetion lost",Toast.LENGTH_SHORT).show();
			//mTouchPadLayout这个页面隐藏
			mTouchpadLayout.setVisibility(View.GONE);
			
			mWriter.close();
			try {
				mSocket.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return;
		}
    	
    	
    	//如果建立连接成功
    	//将message写入到mWriter这个流里面，socket协议自动会发送给服务器
    	mWriter.println(message);
    	//刷新缓存，就是将本次发送的数据清零，便于下一次信息发送，否则消息一直残留
    	mWriter.flush();
    }
    
    
    
    //下面这些全部是安卓系统对应用程序声明周期状态的管理，在应用程序被重启，暂停，和调用系统back键的一些动作定义。
	@Override
	protected void onResume() {
		//仅使用系统本身的管理动作，没有自定义更多
		// TODO Auto-generated method stub
		super.onResume();
	}

	@Override
	protected void onPause() {
		//仅使用系统本身的管理动作，没有自定义更多
		// TODO Auto-generated method stub
		super.onPause();
	}

	
	
	//点击系统back键的动作
	@Override
	public void onBackPressed() {
		if (mTouchpadLayout.getVisibility() == View.VISIBLE) {
			//调用之前定义的停止连接函数
			stopConnection();
			mTouchpadLayout.setVisibility(View.GONE);
			return;
		}
		super.onBackPressed();
	}
}
/*
Command :
MOUSEEVENTF_MOVE x y
MOUSEEVENTF_LEFTDOWN
MOUSEEVENTF_LEFTUP
MOUSEEVENTF_RIGHTDOWN
MOUSEEVENTF_RIGHTUP
MOUSEEVENTF_MIDDLEDOWN
MOUSEEVENTF_MIDDLEUP
MOUSEEVENTF_WHEEL WHEEL_DELTA

reference :
http://msdn.microsoft.com/en-us/library/windows/desktop/ms646273(v=vs.85).aspx
*/