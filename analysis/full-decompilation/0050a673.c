
undefined1 __fastcall FUN_0050a673(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined1 local_3c [16];
  undefined1 local_2c [16];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((*(int *)(param_1 + 0xb4) != 0) && (*(int **)(param_1 + 0xe4) != (int *)0x0)) {
    (**(code **)(**(int **)(param_1 + 0xe4) + 0x168))();
  }
  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
    cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar3 != '\0') {
      iVar1 = *(int *)(param_1 + 0x100);
      iVar2 = **(int **)(param_1 + 0x5c);
      uVar9 = 0;
      puVar6 = local_2c;
      puVar8 = &DAT_006f35e0;
      FUN_004df599(&local_1c,param_1 + 0x1c);
      uVar4 = FUN_004df599(puVar6,puVar8);
      (**(code **)(iVar2 + 0x9c))(*(undefined4 *)(param_1 + 0x100),iVar1 + 0x14,uVar4,uVar9);
      cVar3 = FUN_004cff80();
      if (cVar3 != '\0') {
        cVar3 = (**(code **)(**(int **)(param_1 + 0xe4) + 0x8c))(1);
        if (cVar3 != '\0') {
          iVar1 = *(int *)(param_1 + 0x10c);
          local_c = 0x208;
          local_8 = 0;
          local_1c = *(undefined4 *)(iVar1 + 0x14);
          local_18 = *(undefined4 *)(iVar1 + 0x18);
          local_14 = *(undefined4 *)(iVar1 + 0x1c);
          local_10 = *(undefined4 *)(iVar1 + 0x20);
          puVar7 = &local_c;
          puVar6 = local_2c;
          FUN_004df599(local_3c,param_1 + 0x1c);
          FUN_004df599(puVar6,puVar7);
          FUN_004e609e();
          cVar3 = FUN_004e6133();
          if (cVar3 == '\x01') {
            local_c = 0;
            local_8 = 0;
            uVar4 = *(undefined4 *)(*(int *)(param_1 + 0x10c) + 0x60);
            uVar5 = (**(code **)(**(int **)(param_1 + 0xe4) + 0xb0))();
            FUN_004ba1dc(*(undefined4 *)(param_1 + 0x5c),local_2c,*(undefined4 *)(param_1 + 0x10c),
                         uVar4,&local_c,(uVar5 & 0xff) - 0xff);
          }
          else {
            (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                      (*(undefined4 *)(param_1 + 0x10c),&local_1c,local_2c,0);
          }
        }
      }
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
    }
  }
  return *(undefined1 *)(param_1 + 0x61);
}

