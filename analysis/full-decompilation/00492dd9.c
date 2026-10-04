
void FUN_00492dd9(void)

{
  uint *puVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined1 uVar5;
  int iVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined8 uVar7;
  undefined4 local_40;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0x28) != '\0') {
    pcVar3 = *(char **)(unaff_EBP + 8);
    cVar2 = *pcVar3;
    if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)cVar2) &&
         ((int)cVar2 <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
        (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)pcVar3[1])) &&
       ((int)pcVar3[1] <= *(int *)(DAT_006e54d8 + 0x7c) + -1)) {
      *(undefined4 **)(unaff_EBP + -0x10) = &local_40;
      local_40._3_1_ = (undefined1)((uint)extraout_ECX >> 0x18);
      local_40._0_3_ = CONCAT12(pcVar3[2],CONCAT11(pcVar3[1],cVar2));
      FUN_00467768(unaff_EBP + -0x3c);
      cVar2 = pcVar3[1];
      iVar4 = *(int *)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      puVar1 = (uint *)(iVar4 + cVar2 * 8);
      local_40 = 0x492e72;
      uVar7 = __allshl();
      *puVar1 = *puVar1 | (uint)uVar7;
      puVar1[1] = puVar1[1] | (uint)((ulonglong)uVar7 >> 0x20);
      uVar5 = DAT_006e4822;
      if (((byte)*(undefined4 *)(unaff_EBP + -0x3c) & 1) == 1) {
        *(undefined1 *)(unaff_EBP + 10) = 0;
        *(undefined1 *)(unaff_EBP + 8) = uVar5;
        *(undefined1 *)(unaff_EBP + 9) = DAT_006e4823;
        local_40 = unaff_EBP + 8;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        iVar6 = FUN_0046185f(unaff_EBP + 0xc);
        puVar1 = (uint *)(iVar4 + *(char *)(iVar6 + 1) * 8);
        local_40 = 0x492ebc;
        uVar7 = __allshl();
        *puVar1 = *puVar1 & ~(uint)uVar7;
        puVar1[1] = puVar1[1] & ~(uint)((ulonglong)uVar7 >> 0x20);
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
      uVar5 = DAT_006e481c;
      if (((byte)*(undefined4 *)(unaff_EBP + -0x3c) & 2) == 2) {
        *(undefined1 *)(unaff_EBP + 10) = 0;
        *(undefined1 *)(unaff_EBP + 8) = uVar5;
        *(undefined1 *)(unaff_EBP + 9) = DAT_006e481d;
        local_40 = unaff_EBP + 8;
        *(undefined1 *)(unaff_EBP + -4) = 2;
        iVar6 = FUN_0046185f(unaff_EBP + 0xc);
        puVar1 = (uint *)(iVar4 + *(char *)(iVar6 + 1) * 8);
        local_40 = 0x492f0e;
        uVar7 = __allshl();
        *puVar1 = *puVar1 & ~(uint)uVar7;
        puVar1[1] = puVar1[1] & ~(uint)((ulonglong)uVar7 >> 0x20);
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

