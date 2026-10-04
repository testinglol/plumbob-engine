
void FUN_004eb9be(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 code *param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  
  FUN_004ebb5b(param_1,param_2,param_5,0,0);
  for (puVar4 = param_2; puVar4 < param_3; puVar4 = puVar4 + 1) {
    uVar1 = *param_1;
    uVar2 = *puVar4;
    cVar3 = (*param_5)(uVar2,uVar1);
    if (cVar3 != '\0') {
      *puVar4 = uVar1;
      FUN_00520b50(param_1,0,(int)param_2 - (int)param_1 >> 2,uVar2,param_5);
    }
  }
  FUN_00520b04(param_1,param_2,param_5);
  return;
}

