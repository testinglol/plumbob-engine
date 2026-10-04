
void __thiscall FUN_004d2f53(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x11a8);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 4) == param_2)) {
    FUN_004c286d(0);
    *(undefined1 *)(iVar1 + 0x151) = 0;
  }
  if (*(int *)(param_1 + 0x11bc) != 0) {
    FUN_005254b4(param_2);
  }
  return;
}

