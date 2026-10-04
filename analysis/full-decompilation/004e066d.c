
void FUN_004e066d(HANDLE param_1,LPCSTR param_2)

{
  DWORD nNumberOfBytesToWrite;
  CHAR local_404 [1024];
  
  nNumberOfBytesToWrite = wvsprintfA(local_404,param_2,&stack0x0000000c);
  if (nNumberOfBytesToWrite != 0) {
    WriteFile(param_1,local_404,nNumberOfBytesToWrite,(LPDWORD)&param_1,(LPOVERLAPPED)0x0);
  }
  return;
}

