
undefined1 __thiscall FUN_005e4ae7(int *param_1,undefined1 param_2)

{
  int iVar1;
  
  iVar1 = param_1[0x5c];
  *(undefined1 *)(param_1 + 0x5c) = param_2;
  (**(code **)(*param_1 + 0x168))();
  return (char)iVar1;
}

