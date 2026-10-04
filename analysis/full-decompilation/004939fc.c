
void FUN_004939fc(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iStack_70;
  undefined4 auStack_6c [7];
  undefined4 uStack_50;
  int iStack_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  FUN_00634c24();
  puVar2 = *(undefined1 **)(unaff_EBP + 8);
  uVar1 = *puVar2;
  *(undefined4 **)(unaff_EBP + -0x14) = &local_44;
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  local_44._3_1_ = (undefined1)((uint)extraout_ECX >> 0x18);
  local_44._0_3_ = CONCAT12(puVar2[2],CONCAT11(puVar2[1],uVar1));
  puStack_48 = (undefined1 *)(unaff_EBP + -0x40);
  iStack_4c = 0x493a39;
  FUN_00467768();
  local_44 = *(undefined1 **)(unaff_EBP + 0x14);
  iVar5 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puStack_48 = *(undefined1 **)(unaff_EBP + 0x10);
  iStack_4c = 0x493a4c;
  local_44 = (undefined1 *)FUN_00467e89();
  iVar3 = *(int *)(unaff_EBP + 0xc);
  if ((iVar3 != 1) && (iVar3 != 3)) {
    iVar5 = *(int *)(extraout_ECX + 0x38);
  }
  if (local_44 != (undefined1 *)iVar5) {
    if ((iVar3 == 1) || (iVar3 == 3)) {
      puStack_48 = (undefined1 *)0x493a88;
      uVar4 = FUN_004c6571();
      *(undefined4 *)(unaff_EBP + 8) = uVar4;
      local_44 = (undefined1 *)0x493a9f;
      local_44 = (undefined1 *)__ftol();
    }
    else {
      puStack_48 = (undefined1 *)0x493a7a;
      local_44 = (undefined1 *)iVar5;
      local_44 = (undefined1 *)FUN_004c6571();
    }
    *(undefined1 **)(unaff_EBP + 8) = local_44;
    iStack_4c = 0x493aab;
    puStack_48 = puVar2;
    FUN_004937af();
    local_44 = *(undefined1 **)(unaff_EBP + 0x14);
    puStack_48 = *(undefined1 **)(unaff_EBP + 0x10);
    uStack_50 = 0x493aba;
    iStack_4c = iVar5;
    FUN_00493b0f();
    *(undefined4 **)(unaff_EBP + 0x14) = auStack_6c;
    puVar6 = (undefined4 *)(unaff_EBP + -0x40);
    puVar7 = auStack_6c;
    for (iStack_70 = 0xb; iStack_70 != 0; iStack_70 = iStack_70 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    *(int **)(unaff_EBP + 0x10) = &iStack_70;
    FUN_00461b74(puVar2);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00489224();
    puStack_48 = (undefined1 *)0x493aef;
    local_44 = puVar2;
    FUN_00492be0();
    local_44 = *(undefined1 **)(unaff_EBP + 8);
    puStack_48 = (undefined1 *)0x493afe;
    FUN_00492bb0();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

