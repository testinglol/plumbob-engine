
void __fastcall FUN_0046527c(int *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  if (piVar2 != (int *)param_1[1]) {
    do {
      puVar1 = (undefined4 *)*piVar2;
      if (puVar1 != (undefined4 *)0x0) {
        FUN_0052ea87(*puVar1,puVar1[1]);
        FUN_005481b6();
        FUN_006321f0(puVar1);
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != (int *)param_1[1]);
  }
  FUN_0052ea87(*param_1,param_1[1]);
  return;
}

