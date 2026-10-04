
void __fastcall FUN_005d96f2(undefined4 param_1)

{
  int *piVar1;
  undefined *puVar2;
  code *pcVar3;
  char *pcVar4;
  
  piVar1 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 8))();
  pcVar4 = s_Usage__tips_006d7310;
  pcVar3 = FUN_005daecc;
  puVar2 = &DAT_006d7308;
  (**(code **)(*piVar1 + 0x1b8))(&DAT_006d7308,FUN_005daecc,param_1,s_Usage__tips_006d7310);
  FUN_005e6125(puVar2,pcVar3,param_1,pcVar4);
  return;
}

