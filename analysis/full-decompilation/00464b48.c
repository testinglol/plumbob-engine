
void __thiscall FUN_00464b48(int *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = param_1[3];
  if (*(char *)((int)param_1 + 0x13) == '\0') {
    if (iVar4 == 2) {
      param_1[2] = param_1[2] + param_3 * 4;
    }
    else {
      if (iVar4 == 0) {
        puVar2 = (undefined4 *)(param_1[2] + *param_1);
        puVar3 = param_2;
      }
      else {
        puVar3 = (undefined4 *)(param_1[2] + *param_1);
        puVar2 = param_2;
      }
      if (0 < param_3) {
        do {
          uVar1 = *puVar2;
          puVar2 = puVar2 + 1;
          *puVar3 = uVar1;
          param_1[2] = param_1[2] + 4;
          puVar3 = puVar3 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
  }
  else if ((iVar4 == 1) || (iVar4 == 2)) {
    iVar4 = param_3;
    puVar2 = param_2;
    if (0 < param_3) {
      do {
        param_2 = (undefined4 *)*puVar2;
        FUN_00464696(&param_2,&DAT_006e52a8);
        iVar4 = iVar4 + -1;
        puVar2 = puVar2 + 1;
      } while (iVar4 != 0);
    }
  }
  else {
    iVar4 = param_3;
    puVar2 = param_2;
    if (0 < param_3) {
      do {
        FUN_00464696(&param_2,&DAT_006e52a8);
        *puVar2 = param_2;
        iVar4 = iVar4 + -1;
        puVar2 = puVar2 + 1;
      } while (iVar4 != 0);
    }
  }
  return;
}

