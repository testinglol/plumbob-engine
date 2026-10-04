
void __thiscall FUN_00533028(int param_1,char param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xf8);
  if (iVar1 != 0) {
    if (DAT_006d74f0 == 0) {
      *(undefined4 *)(iVar1 + 0x154) = 0;
    }
    else {
      *(int *)(iVar1 + 0x158) = DAT_006d74f0;
      *(uint *)(iVar1 + 0x154) = (uint)(param_2 != '\0');
    }
    *(undefined1 *)(iVar1 + 0x16c) = 0;
  }
  return;
}

