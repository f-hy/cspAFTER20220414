#include<bits/stdc++.h>
using namespace std;
#define filePath "D:/programs/vscode/after20220414/favor"
#define fileName "/test.png"
void Merge() {
  char name[20];
  string str1 = filePath"./1.png";
  string str2 = "F:/数据/2.jpg";
  string strBlock = "F:/数据/BLOCK.dat";
  FILE* f1 = fopen(str1.c_str(),"rb+");
  FILE* f2 = fopen(str2.c_str(),"rb+");
  FILE* f3 = fopen(strBlock.c_str(),"rb+");
  // 获取文件的长度
  int iLen1 =filelength(fileno(f1));
  int iLen2 = filelength(fileno(f2));
  char *buf1 = new char[iLen1];  
  memset(buf1,0x0,iLen1);  
  char *buf2 = new char[iLen2];  
  memset(buf2,0x0,iLen2);  
  // 获取文件内容 
  fread(buf1,iLen1,1,f1);  
  fread(buf2,iLen2,1,f2);
  fclose(f1);
  fclose(f2);
  // 在文件头记录合并文件的个数 
  int iCount = 2; 
  fseek(f3,0,SEEK_SET); 
  fwrite(&iCount,sizeof(int),1,f3); 
  // 写入第一个文件 
  memset(name,0x0,20);  
  strcpy(name,str1.c_str()); 
  fwrite(name,20,1,f3);  
  fwrite(&iLen1,sizeof(int),1,f3);  
  fwrite(buf1,iLen1,1,f3);  
  // 写入第二个文件 
  memset(name,0x0,20);  
  strcpy(name,str2.c_str()); 
  fwrite(name,20,1,f3);  
  fwrite(&iLen2,sizeof(int),1,f3);  
  fwrite(buf2,iLen2,1,f3);   
  fclose(f3);
  //删除申请的内存    
  delete[] buf1;   
  delete[] buf2;  
}
void Split() { 
  char name[20];
  string strBlock = "F:/数据/BLOCK.dat";
  FILE* f3 = fopen(strBlock.c_str(),"rb+"); 
  // 获取文件数量 
  int iCount = 0; 
  fseek(f3,0,SEEK_SET); 
  fread(&iCount,sizeof(int),1,f3); 
  for(int i=0;i<iCount;i++) { 
    memset(name,0x0,20); 
    fread(&name,20,1,f3); 
    // 输出名称 
    cout<<name<<endl; 
    int iLen = 0; 
    // 读取文件长度 
    fread(&iLen,sizeof(int),1,f3); 
    char *buff = new char[iLen]; 
    // 读取文件内容 
    fread(buff,iLen,1,f3); 
    char fileLen[10]; 
    sprintf(fileLen, "%d", iLen); 
    // 以文件长度做名称 
    string s = fileLen; 
    string strName = "F:/数据/"; 
    strName += s; 
    strName += string(".jpg") ; 
    // 新建一个文件 
    FILE* file= fopen(strName.c_str(),"wb+");
    fwrite(buff,iLen,1,file);
    fclose(file);
  }
  fclose(f3);
}
int main(){
    return 0;
}