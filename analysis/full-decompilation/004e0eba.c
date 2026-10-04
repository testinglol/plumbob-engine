
DWORD FUN_004e0eba(LPCSTR param_1)

{
  DWORD nNumberOfBytesToWrite;
  CHAR local_408 [1024];
  DWORD local_8;
  
  nNumberOfBytesToWrite = wvsprintfA(local_408,param_1,&stack0x00000008);
  WriteFile(DAT_006f2230,local_408,nNumberOfBytesToWrite,&local_8,(LPOVERLAPPED)0x0);
  return nNumberOfBytesToWrite;
}

