
void __thiscall FUN_004e6387(int param_1,undefined1 param_2)

{
  int iVar1;
  int *piVar2;
  
  *(undefined1 *)(param_1 + 0xc) = param_2;
  if ((DAT_006f2a08 != 0) && (*(int *)(DAT_006f2a08 + 0x84) != 0)) {
    iVar1 = FUN_004d4090();
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_004d4090();
      (**(code **)(*piVar2 + 0x50))(*(undefined1 *)(param_1 + 0xc));
    }
  }
  return;
}

