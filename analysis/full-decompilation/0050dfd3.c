
undefined4 __fastcall FUN_0050dfd3(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 local_40 [16];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar3 != '\0') {
      iVar7 = *(int *)(param_1 + 0xf0);
      local_20 = *(undefined4 *)(iVar7 + 0x14);
      local_1c = *(undefined4 *)(iVar7 + 0x18);
      local_18 = *(int *)(iVar7 + 0x1c) / 3;
      local_14 = *(int *)(iVar7 + 0x20) / 3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar7,&local_20,param_1 + 0x1c,1);
      iVar7 = *(int *)(param_1 + 0xec);
      uVar8 = 0;
      local_20 = *(undefined4 *)(iVar7 + 0x14);
      local_1c = *(undefined4 *)(iVar7 + 0x18);
      local_18 = *(undefined4 *)(iVar7 + 0x1c);
      local_14 = *(undefined4 *)(iVar7 + 0x20);
      local_8 = **(int **)(param_1 + 0x5c);
      iVar7 = param_1 + 0x100;
      piVar5 = &local_30;
      FUN_004df599(local_40,param_1 + 0x1c);
      uVar4 = FUN_004df599(piVar5,iVar7);
      (**(code **)(local_8 + 0x9c))(*(undefined4 *)(param_1 + 0xec),&local_20,uVar4,uVar8);
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
      if (*(char *)(param_1 + 0xe0) != '\0') {
        piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
        piVar5 = (int *)(**(code **)(*piVar5 + 0x10))(1,0xc,0,0);
        local_8 = param_1 + 0xd4;
        iVar7 = *piVar5;
        uVar4 = FUN_005d49d6();
        uVar4 = FUN_004096c2(uVar4);
        (**(code **)(iVar7 + 0x50))(&local_30,uVar4);
        local_c = (((*(int *)(*(int *)(param_1 + 0xf4) + 0x80) -
                    *(int *)(*(int *)(param_1 + 0xf4) + 0x88)) + *(int *)(param_1 + 0x28)) -
                  local_24) + -9 + local_2c;
        iVar7 = *(int *)(param_1 + 0x1c);
        iVar1 = *(int *)(param_1 + 0x24);
        local_10 = *(undefined4 *)(param_1 + 0x5c);
        iVar2 = *piVar5;
        uVar4 = FUN_005d49d6(0,0,0);
        uVar4 = FUN_004096c2(uVar4);
        (**(code **)(iVar2 + 0x78))
                  (local_10,((iVar1 - iVar7) / 2 - (local_28 - local_30) / 2) + iVar7,local_c,uVar4)
        ;
        piVar6 = (int *)(**(code **)(*DAT_006fe8bc + 0x10))();
        (**(code **)(*piVar6 + 0x14))(piVar5);
      }
    }
  }
  return 1;
}

