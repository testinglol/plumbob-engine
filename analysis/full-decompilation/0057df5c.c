
undefined4 __fastcall FUN_0057df5c(int *param_1)

{
  char cVar1;
  
  param_1[0x72] = 0;
  cVar1 = (**(code **)(*param_1 + 0x70))();
  if (cVar1 != '\0') {
    if ((int *)param_1[0x74] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0x74] + 0x5c))();
    }
    param_1[0x66] = *(int *)(DAT_006f6a78 + 0x58);
    FUN_0057d310(param_1);
  }
  return 1;
}

