
void FUN_00501db9(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  
  FUN_00501ed2(param_1,param_2,param_5);
  for (puVar3 = param_2; puVar3 < param_3; puVar3 = puVar3 + 1) {
    cVar2 = FUN_00501cfd(*puVar3,*param_1);
    if (cVar2 != '\0') {
      uVar1 = *puVar3;
      *puVar3 = *param_1;
      FUN_00501f69(param_1,0,(int)param_2 - (int)param_1 >> 2,uVar1,param_5);
    }
  }
  FUN_00501f1d(param_1,param_2,param_5);
  return;
}

