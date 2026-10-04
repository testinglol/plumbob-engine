
uint __fastcall FUN_005de012(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  while( true ) {
    uVar1 = (**(code **)(*param_1 + 0x8c))(1);
    if ((char)uVar1 == '\0') {
      return uVar1 & 0xffffff00;
    }
    iVar2 = (**(code **)(*param_1 + 0x18))();
    if (iVar2 == 0) break;
    param_1 = (int *)(**(code **)(*param_1 + 0x18))();
  }
  uVar1 = (**(code **)(*param_1 + 0x8c))(1);
  return uVar1;
}

