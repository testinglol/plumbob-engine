
void FUN_00401742(void)

{
  uint _Size;
  int *piVar1;
  void *pvVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  _Size = *(uint *)(unaff_EBP + 8);
  if (_Size < 0x81) {
    FUN_004017b8();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    piVar1 = *(int **)(&DAT_006de560 + (_Size + 7 >> 3) * 4);
    if (piVar1 == (int *)0x0) {
      FUN_00401ae2(_Size + 7 & 0xfffffff8);
    }
    else {
      *(int *)(&DAT_006de560 + (_Size + 7 >> 3) * 4) = *piVar1;
    }
    DAT_006de5a4 = 0;
  }
  else {
    pvVar2 = _malloc(_Size);
    if (pvVar2 == (void *)0x0) {
      FUN_00401b39(_Size);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

