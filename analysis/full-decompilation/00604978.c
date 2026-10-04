
void __fastcall FUN_00604978(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_006fe8bc + 0x10))();
  piVar2 = (int *)(**(code **)(*param_1 + 0x38))();
  (**(code **)(*piVar2 + 4))(-(uint)(iVar1 != 0) & iVar1 + 4U);
  FUN_005d969a();
  FUN_005d5c22();
  return;
}

