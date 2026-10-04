
int __fastcall FUN_0045c4b5(int param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xaf4) - *(int *)(param_1 + 0xaf0)) / 0x9c == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = ((*(int *)(param_1 + 0xaf4) - *(int *)(param_1 + 0xaf0)) / 0x9c) * 0x9c + -0x9c +
            *(int *)(param_1 + 0xaf0);
  }
  return iVar1;
}

