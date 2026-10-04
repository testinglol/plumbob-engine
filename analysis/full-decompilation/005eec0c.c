
void * FUN_005eec0c(void)

{
  void *_Dst;
  int unaff_EBP;
  
  FUN_00634c24();
  *(void **)(unaff_EBP + -0x10) = _Dst;
  *(undefined4 *)((int)_Dst + 0x10) = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined4 *)((int)_Dst + 0x2c) = 0;
  *(undefined4 *)((int)_Dst + 0x30) = 0;
  *(undefined4 *)((int)_Dst + 0x34) = 0;
  _memset(_Dst,0,0x10);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return _Dst;
}

