
void FUN_005c0d5d(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint in_stack_00000018;
  
  do {
    if (in_stack_00000018 <= (uint)param_1[3]) {
      do {
        puVar5 = param_2;
        param_2 = puVar5 + -4;
      } while (in_stack_00000018 < (uint)puVar5[-1]);
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

