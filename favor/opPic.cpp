#include<bits/stdc++.h>
using namespace std;
const string filePath="D:/programs/vscode/after20220414/favor";
const string fileName="/test.png";

//将文件拆分到指定路径
int SplitFile(string filepath,string tofilepath)
{
	int count;//已拆分的文件个数
	int size = 0;//预计拆分的文件个数
	int readfd = 0;//读文件
	int writefd = 0;//写文件
	int resbuf = 0;//读到的字符数
	char buf[102400] = { 0 };//每个文件的大小
	int num = 1;//拆分文件的文件名序号
	string writePath;//拆分生成的文件名
	int pid = 0;//子进程的pid
	int res = 0;//父进程接收到的子进程pid
	int status = 0;//接收到子进程完成所返回的信息
	struct stat s_buf;//文件信息
	umask(0);
	stat(filepath.c_str(), &s_buf);
	if (!S_ISREG(s_buf.st_mode))
	{//不是文件,直接结束
		cout << "所给的路径并非文件路径,函数结束" << endl;
		return -1;
	}
	cout << "需要拆分的文件大小为:" << s_buf.st_size << endl;
	size = ceil(float(s_buf.st_size / 102400.00));//计算需要拆分文件的个数,向上取整
	cout << "需要拆分的文件个数为:" << size << endl;
	readfd = open(filepath.c_str(), O_RDONLY, 0777);
	if (read < 0)
	{
		perror("文件读取失败");
		return -1;
	}
	else
	{
		while ((resbuf = read(readfd, buf, sizeof(buf))) > 0)
		{
			writePath = tofilepath + to_string(num) + ".tmp";
 
			cout << "写路径:" << writePath << endl;
			num++;
			pid = fork();
			if (pid == 0)
			{//子进程做拆分
				writefd = open(writePath.c_str(), O_CREAT | O_WRONLY, 0777);
				int res = write(writefd, buf, resbuf);
				if (res > 0)
				{
					close(writefd);
					bzero(buf, sizeof(buf));
					writePath.clear();
				}
				else
				{
					perror("读取失败");
				}
				exit(0);
			}
			else if (pid > 0)
			{
 
			}
		}
		//父进程
		while (count < size)
		{
			res = wait(&status);
			if (res > 0)
			{
				//cout << "res=" << res << "拆分完毕" << endl;
				cout << "已经等待了第" << count << "个子进程" << endl;
				count++;
			}
		}
		cout << "所有拆分完毕" << endl;
		return 0;
	}
}