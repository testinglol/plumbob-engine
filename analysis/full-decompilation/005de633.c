
void __fastcall FUN_005de633(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  (**(code **)(*param_1 + 0x90))(1,0);
  piVar1 = (int *)FUN_005d0a09();
  if (param_1 == piVar1) {
    iVar2 = (**(code **)(*param_1 + 0x18))();
    if (iVar2 == 0) {
      FUN_004b46a0();
    }
    else {
      (**(code **)(*param_1 + 0x18))();
    }
    FUN_00436e16();
  }
  return;
}

