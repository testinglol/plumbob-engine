
void FUN_004a9e60(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  byte bVar7;
  undefined4 extraout_ECX;
  int iVar8;
  int unaff_EBP;
  undefined4 local_18;
  
  FUN_00634c24();
  cVar1 = *(char *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  cVar2 = *(char *)(unaff_EBP + 0xc);
  *(char *)(unaff_EBP + -0x10) = cVar2;
  *(char *)(unaff_EBP + -0xf) = cVar1;
  *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + 0x11) = 0;
  if (*(undefined1 **)(unaff_EBP + 0x1c) == (undefined1 *)0x0) {
    if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)cVar2) &&
         ((int)cVar2 <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
        (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)cVar1)) &&
       ((int)cVar1 <= *(int *)(DAT_006e54d8 + 0x7c) + -1)) {
      *(undefined4 **)(unaff_EBP + 0x14) = &local_18;
      local_18._3_1_ = (undefined1)((uint)extraout_ECX >> 0x18);
      local_18._0_3_ =
           CONCAT12(*(undefined1 *)(unaff_EBP + -0xe),
                    CONCAT11(*(undefined1 *)(unaff_EBP + -0xf),cVar2));
      puVar6 = (undefined4 *)FUN_004796d9(unaff_EBP + 0x10);
      *(undefined4 *)(unaff_EBP + 0x10) = *puVar6;
    }
  }
  else {
    *(undefined1 *)(unaff_EBP + 0x11) = **(undefined1 **)(unaff_EBP + 0x1c);
  }
  iVar5 = DAT_006f0088;
  iVar4 = DAT_006f0084;
  iVar3 = *(int *)(unaff_EBP + 0x18);
  if (iVar3 == DAT_006f0088) {
    local_18 = unaff_EBP + -0x10;
    FUN_004b3e97(unaff_EBP + 0x1c,unaff_EBP + 0x14);
    *(int *)(unaff_EBP + 0x14) =
         *(int *)(unaff_EBP + 0x14) -
         ((uint)*(byte *)(unaff_EBP + 0x11) << ((char)DAT_006f0088 + 1U & 0x1f));
  }
  else {
    *(int *)(unaff_EBP + 0x18) = DAT_006f0080;
    bVar7 = (byte)(DAT_006f0088 - iVar3);
    if (DAT_006f0088 - iVar3 < 1) {
      iVar8 = 1 << (-bVar7 & 0x1f);
      DAT_006f0080 = iVar8 * DAT_006f0080;
      DAT_006f0084 = iVar8 * DAT_006f0084;
    }
    else {
      iVar8 = 1 << (bVar7 & 0x1f);
      DAT_006f0080 = DAT_006f0080 / iVar8;
      DAT_006f0084 = DAT_006f0084 / iVar8;
    }
    local_18 = unaff_EBP + -0x10;
    DAT_006f0088 = iVar3;
    FUN_004b3e97(unaff_EBP + 0x1c,unaff_EBP + 0x14);
    cVar1 = (char)DAT_006f0088;
    DAT_006f0084 = iVar4;
    DAT_006f0088 = iVar5;
    *(int *)(unaff_EBP + 0x14) =
         *(int *)(unaff_EBP + 0x14) - ((uint)*(byte *)(unaff_EBP + 0x11) << (cVar1 + 1U & 0x1f));
    DAT_006f0080 = *(int *)(unaff_EBP + 0x18);
  }
  *(undefined2 *)(unaff_EBP + 0x1e) = *(undefined2 *)(unaff_EBP + 0x1c);
  *(undefined2 *)(unaff_EBP + 0x1c) = *(undefined2 *)(unaff_EBP + 0x14);
  **(undefined4 **)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + 0x1c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

