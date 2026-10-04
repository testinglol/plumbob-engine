
void __fastcall FUN_00540596(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  *param_1 = &PTR_FUN_0066f3d8;
  if (param_1[10] != 0) {
    FUN_0053d900();
  }
  piVar3 = param_1 + 4;
  iVar2 = 2;
  do {
    iVar1 = piVar3[-2];
    if (iVar1 != 0) {
      FUN_00540f8b();
      FUN_006321f0(iVar1);
    }
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      FUN_00541016();
      FUN_006321f0(iVar1);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (param_1[0xb] != 0) {
    FUN_0053d900();
  }
  if (param_1[0xc] != 0) {
    FUN_0053d900();
  }
  if (param_1[0xd] != 0) {
    FUN_0053c286();
    param_1[0xd] = 0;
  }
  return;
}

