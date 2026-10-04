
uint FUN_004950b8(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int iVar3;
  char cVar7;
  undefined4 *puVar4;
  char cVar8;
  uint uVar5;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 local_10;
  undefined4 uVar6;
  
  FUN_00634c24();
  puVar2 = *(undefined1 **)(unaff_EBP + 8);
  uVar1 = *puVar2;
  *(undefined4 **)(unaff_EBP + -0x10) = &local_10;
  local_10._0_2_ = CONCAT11(puVar2[1],uVar1);
  local_10._3_1_ = (undefined1)((uint)extraout_ECX >> 0x18);
  local_10._0_3_ = CONCAT12(puVar2[2],(undefined2)local_10);
  FUN_004796d9(unaff_EBP + -0x10);
  uVar6 = *(undefined4 *)(unaff_EBP + -0x10);
  cVar7 = (char)((uint)uVar6 >> 8);
  if ((((cVar7 == *(char *)(extraout_ECX + 0xe02f)) && (cVar7 == (char)uVar6)) &&
      (cVar7 == *(char *)(unaff_EBP + -0xe))) && (cVar7 == *(char *)(unaff_EBP + -0xd))) {
    if ((*(int *)(unaff_EBP + 0xc) != 0x10) && (*(int *)(unaff_EBP + 0xc) != 0x20)) {
      *(undefined1 *)(unaff_EBP + 8) = *puVar2;
      *(undefined1 *)(unaff_EBP + 9) = puVar2[1];
      *(undefined1 *)(unaff_EBP + 10) = puVar2[2];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      local_10 = unaff_EBP + 8;
      FUN_0053c0e0(*(undefined4 *)(unaff_EBP + 0xc));
      iVar3 = local_10;
      *(undefined4 **)(unaff_EBP + 0xc) = &local_10;
      local_10._0_2_ = CONCAT11(*(undefined1 *)(unaff_EBP + 9),*(undefined1 *)(unaff_EBP + 8));
      local_10._3_1_ = SUB41(iVar3,3);
      local_10._0_3_ = CONCAT12(*(undefined1 *)(unaff_EBP + 10),(undefined2)local_10);
      puVar4 = (undefined4 *)FUN_004796d9(unaff_EBP + 0xc);
      uVar6 = *puVar4;
      cVar7 = *(char *)(extraout_ECX + 0xe02f);
      cVar8 = (char)((uint)uVar6 >> 8);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      if (((cVar8 != cVar7) || ((cVar8 != (char)uVar6 || (cVar8 != *(char *)(unaff_EBP + -0xe)))))
         || (cVar8 != *(char *)(unaff_EBP + -0xd))) goto LAB_0049517e;
    }
    uVar5 = CONCAT31((int3)((uint)uVar6 >> 8),1);
  }
  else {
LAB_0049517e:
    if (*(int *)(extraout_ECX + 0xe064) == 0) {
      *(undefined4 *)(extraout_ECX + 0xe064) = 0x11;
    }
    uVar5 = (uint)(extraout_ECX + 0xe064) & 0xffffff00;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

