
void FUN_005dba4f(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  do {
    if (param_5 <= (int)param_1[2]) {
      do {
        puVar5 = param_2;
        param_2 = puVar5 + -4;
      } while (param_5 < (int)puVar5[-2]);
      if (param_2 <= param_1) {
        return;
      }
      uVar1 = *param_1;
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      *param_1 = *param_2;
      param_1[1] = puVar5[-3];
      param_1[2] = puVar5[-2];
      param_1[3] = puVar5[-1];
      *param_2 = uVar1;
      puVar5[-3] = uVar2;
      puVar5[-2] = uVar3;
      puVar5[-1] = uVar4;
    }
    param_1 = param_1 + 4;
  } while( true );
}

