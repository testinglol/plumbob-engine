
BOOL FUN_004e0167(int *param_1)

{
  char cVar1;
  BOOL BVar2;
  
  cVar1 = FUN_004e0015();
  if ((cVar1 == '\0') || (*param_1 != 0x50594f52)) {
    BVar2 = 0;
  }
  else {
    BVar2 = VirtualFree(param_1,0,0x8000);
  }
  return BVar2;
}

