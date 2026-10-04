
undefined4 __fastcall FUN_0050e78c(int param_1)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  CHAR local_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if ((DAT_006f365c & 1) == 0) {
    DAT_006f365c = DAT_006f365c | 1;
    uVar2 = FUN_0049a996(0x1f);
    DAT_006f3658 = uVar2 & 0xffff;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x1b8) + 0x1c) / 2;
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 != '\0') {
    local_24 = *(undefined4 *)(*(int *)(param_1 + 0x1b8) + 0x20);
    local_30 = 0;
    local_2c = 0;
    local_20 = 0;
    local_1c = 0;
    local_10 = *(int *)(param_1 + 0x1c) +
               ((*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c)) - iVar5) / 2;
    local_c = *(undefined4 *)(param_1 + 0x20);
    local_28 = iVar5;
    local_18 = iVar5;
    local_14 = local_24;
    FUN_004ba5ac(&local_10);
    if (*(int *)(param_1 + 0x1b8) == 0) {
      iVar5 = **(int **)(param_1 + 0x5c);
      uVar3 = FUN_004096c2(&local_30,&local_20,0);
      (**(code **)(iVar5 + 0x9c))(uVar3);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                (*(int *)(param_1 + 0x1b8),&local_30,&local_20,0);
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  piVar4 = (int *)FUN_005e40a5();
  if (piVar4 != (int *)0x0) {
    local_c = (**(code **)(*piVar4 + 0x1c))();
    (**(code **)(*piVar4 + 0x20))(DAT_006f3658);
    local_8 = wsprintfA(local_40,(LPCSTR)&DAT_006c08e4,(int)*(short *)(param_1 + 0x198));
    local_20 = 0;
    local_1c = *(int *)(*(int *)(param_1 + 0x1b8) + 0x20) + 3;
    local_18 = 0x2a;
    local_14 = (**(code **)(*piVar4 + 0x58))();
    local_14 = local_14 + local_1c;
    FUN_004ba5ac(param_1 + 0x1c);
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(1);
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x4c))(DAT_006f2a58,&local_20);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(1);
    }
    (**(code **)(*piVar4 + 0x80))(*(undefined4 *)(param_1 + 0x5c),&local_20,local_40,local_8,1);
    (**(code **)(*piVar4 + 0x20))(local_c);
  }
  return 1;
}

