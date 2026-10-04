
void __thiscall FUN_0050c694(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    param_1[0x3c] = 0;
    *(undefined1 *)((int)param_1 + 0xdd) = 1;
  }
  else {
    param_1[0x3c] = param_2;
    *(undefined1 *)((int)param_1 + 0xdd) = 0;
  }
  *(undefined1 *)(param_1 + 0x37) = 0;
  *(undefined1 *)((int)param_1 + 0xde) = 0;
  iVar1 = 5;
  do {
    FUN_0050c54c(0x52,0x52,0);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  (**(code **)(*param_1 + 0x168))();
  return;
}

