
undefined4 __thiscall FUN_005dc557(undefined4 *param_1,int *param_2,int *param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 extraout_ECX;
  undefined4 *puVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *local_c;
  undefined4 uStack_8;
  
  if ((((param_2 == param_3) ||
       (local_c = param_1, uStack_8 = param_1, cVar1 = FUN_005da398(param_2), cVar1 == '\0')) ||
      (cVar1 = FUN_005da398(param_3), cVar1 == '\0')) ||
     (cVar1 = (**(code **)(*param_2 + 0x8c))(0x10), cVar1 == '\0')) {
    return 0;
  }
  if (*(char *)(param_1 + 0xf) == '\0') {
    *(undefined1 *)(param_1 + 0xf) = 1;
  }
  puVar7 = (undefined4 *)param_1[0xe];
  uStack_8 = (undefined4 *)((uint)uStack_8 & 0xffff);
  puVar2 = (undefined4 *)*puVar7;
  puVar3 = puVar2;
  local_c = puVar2;
  do {
    if ((puVar2 == puVar7) || (puVar3 == puVar7)) goto LAB_005dc635;
    if ((int *)puVar2[2] == param_2) {
      bVar4 = uStack_8._2_1_ != '\0';
      uStack_8 = (undefined4 *)CONCAT13(1,(undefined3)uStack_8);
      if (bVar4) {
        FUN_00580b0a(&param_3,puVar2);
        puVar7 = &param_2;
        uVar6 = 1;
        uVar5 = extraout_ECX;
        FUN_00602c56(&local_c);
        FUN_005de794(uVar5,uVar6,puVar7);
LAB_005dc635:
        *(undefined1 *)(param_1 + 0xf) = 0;
        return 1;
      }
    }
    if ((int *)puVar3[2] == param_3) {
      uStack_8._0_3_ = CONCAT12(1,(undefined2)uStack_8);
      if (uStack_8._3_1_ != '\0') goto LAB_005dc635;
    }
    if (uStack_8._3_1_ == '\0') {
      puVar2 = (undefined4 *)*puVar2;
    }
    if (uStack_8._2_1_ == '\0') {
      puVar3 = (undefined4 *)*puVar3;
      local_c = puVar3;
    }
  } while( true );
}

