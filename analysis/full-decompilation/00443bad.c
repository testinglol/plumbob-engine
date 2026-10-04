
void __fastcall FUN_00443bad(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = *(int *)(param_1 + 0x38);
  FUN_0044845a(&stack0x00000004);
  if ((iVar1 - iVar2 >> 2 != 0) != (*(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38) >> 2 != 0))
  {
    FUN_0040766a(0x108,0);
  }
  return;
}

