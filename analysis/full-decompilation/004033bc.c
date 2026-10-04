
undefined4 __thiscall FUN_004033bc(int param_1,char param_2)

{
  int iVar1;
  
  if ((param_2 != '\0') && (iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x1f8))(), iVar1 != 0)) {
    return *(undefined4 *)(param_1 + 0x1fc);
  }
  return *(undefined4 *)(param_1 + 0x170);
}

