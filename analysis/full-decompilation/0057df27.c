
undefined4 __fastcall FUN_0057df27(int *param_1)

{
  char cVar1;
  
  param_1[0x72] = 1;
  cVar1 = (**(code **)(*param_1 + 0x70))();
  if (cVar1 != '\0') {
    if ((int *)param_1[0x74] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x74] + 0x58))();
    }
    FUN_0057d349(param_1);
  }
  return 1;
}

