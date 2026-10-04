
void FUN_004a772c(void)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  char cVar6;
  int extraout_ECX;
  int iVar7;
  int unaff_EBP;
  undefined4 local_34;
  
  FUN_00634c24();
  pcVar2 = *(char **)(unaff_EBP + 8);
  cVar6 = *pcVar2;
  if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)cVar6) &&
       ((int)cVar6 <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
      (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)pcVar2[1])) &&
     (((int)pcVar2[1] <= *(int *)(DAT_006e54d8 + 0x7c) + -1 &&
      ((int)pcVar2[2] <= *(int *)(extraout_ECX + 0x18))))) {
    *(undefined4 **)(unaff_EBP + -0x20) = &local_34;
    local_34._3_1_ = (undefined1)((uint)extraout_ECX >> 0x18);
    local_34._0_3_ = CONCAT12(pcVar2[2],CONCAT11(pcVar2[1],cVar6));
    FUN_004796d9(unaff_EBP + -0x14);
    bVar1 = *(byte *)(unaff_EBP + -0x13);
    local_34 = pcVar2;
    FUN_004b3e97(unaff_EBP + -0x1c,unaff_EBP + -0x10);
    iVar5 = DAT_006f0088;
    cVar6 = (char)DAT_006f0088;
    *(undefined4 *)(unaff_EBP + 8) = 3;
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) << (cVar6 - 1U & 0x1f);
    iVar3 = *(int *)(extraout_ECX + 0x58);
    iVar7 = *(int *)(unaff_EBP + -0x10) - ((uint)bVar1 << (cVar6 + 1U & 0x1f));
    *(int *)(unaff_EBP + -0x10) = iVar7;
    *(int *)(unaff_EBP + -0x30) =
         ((*(int *)(unaff_EBP + -0x1c) - iVar3) - *(int *)(unaff_EBP + 8)) + -1;
    *(int *)(unaff_EBP + -0x28) =
         *(int *)(extraout_ECX + 0x58) + *(int *)(unaff_EBP + 8) + 1 + *(int *)(unaff_EBP + -0x1c);
    iVar3 = *(int *)(extraout_ECX + 0x60);
    *(int *)(unaff_EBP + -0x24) = iVar3 + 1 + iVar7;
    cVar6 = (char)*(undefined4 *)(unaff_EBP + -0x14);
    *(int *)(unaff_EBP + -0x2c) = (iVar7 - iVar3) - *(int *)(extraout_ECX + (0x4c - iVar5) * 4);
    uVar4 = DAT_006e482b;
    if ((cVar6 != *(char *)(unaff_EBP + -0x12)) ||
       ((cVar6 != (char)((uint)*(undefined4 *)(unaff_EBP + -0x14) >> 8) ||
        (cVar6 != *(char *)(unaff_EBP + -0x11))))) {
      *(undefined1 *)(unaff_EBP + 10) = 0;
      *(undefined1 *)(unaff_EBP + 8) = uVar4;
      *(undefined1 *)(unaff_EBP + 9) = DAT_006e482c;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      local_34 = (char *)(unaff_EBP + 8);
      FUN_0046185f(unaff_EBP + -0x18);
      iVar3 = DAT_006e54d8;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      if ((*(int *)(iVar3 + 0x70) <= (int)*(char *)(unaff_EBP + -0x18)) &&
         ((((int)*(char *)(unaff_EBP + -0x18) <= *(int *)(iVar3 + 0x74) &&
           (*(int *)(iVar3 + 0x78) <= (int)*(char *)(unaff_EBP + -0x17))) &&
          ((int)*(char *)(unaff_EBP + -0x17) <= *(int *)(iVar3 + 0x7c))))) {
        local_34 = (char *)(unaff_EBP + -0x18);
        bVar1 = *(byte *)(unaff_EBP + -0x11);
        FUN_004b3e97(unaff_EBP + -0x1c,unaff_EBP + -0x10);
        *(int *)(unaff_EBP + -0x10) =
             *(int *)(unaff_EBP + -0x10) - ((uint)bVar1 << ((char)DAT_006f0088 + 1U & 0x1f));
        *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x10);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    local_34 = (char *)0x4a78b7;
    FUN_004a7901();
    if ((*(int *)(unaff_EBP + -0x30) < *(int *)(unaff_EBP + -0x28)) &&
       (*(int *)(unaff_EBP + -0x2c) < *(int *)(unaff_EBP + -0x24))) {
      *(undefined4 *)(unaff_EBP + -0x20) = DAT_006fe838;
      DAT_006fe838 = DAT_006d6180;
      local_34 = (char *)(unaff_EBP + -0x30);
      FUN_005cddcf();
      DAT_006fe838 = *(undefined4 *)(unaff_EBP + -0x20);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

