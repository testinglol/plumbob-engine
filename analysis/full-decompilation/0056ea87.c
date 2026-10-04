
void FUN_0056ea87(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  byte bVar4;
  char cVar5;
  int *piVar6;
  int extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_0056e1dc(*(undefined4 *)(unaff_EBP + 8));
  iVar7 = 0;
  if ((*(int *)(unaff_EBP + 0xc) != 0) &&
     (iVar8 = *(int *)(extraout_ECX + 0xc), *(int *)(unaff_EBP + -0x10) = iVar8, 0 < iVar8)) {
    do {
      iVar8 = 0;
      do {
        piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x18,iVar7);
        iVar1 = *piVar6;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar2 = iVar8 * 2;
        if ((*(byte *)(iVar2 + iVar1) & 1) == 0) {
LAB_0056eaff:
          bVar3 = false;
        }
        else {
          piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x1c,iVar7);
          bVar4 = (byte)~*(byte *)(*piVar6 + iVar2) >> 2 & 1;
          *(byte *)(unaff_EBP + 0xb) = bVar4;
          if (bVar4 == 0) goto LAB_0056eaff;
          bVar3 = true;
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        if (bVar3) {
          piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x20,iVar7);
          *(byte *)(*piVar6 + iVar2) = *(byte *)(*piVar6 + iVar2) & 0xfe;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(unaff_EBP + -0x10));
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(unaff_EBP + -0x10));
  }
  FUN_0056e3da(*(undefined4 *)(unaff_EBP + 0xc));
  for (iVar7 = 0;
      (((cVar5 = FUN_0056e5fc(), cVar5 == '\0' || (cVar5 = FUN_0056e742(), cVar5 == '\0')) ||
       (cVar5 = FUN_0056e8e9(), cVar5 == '\0')) && (iVar7 < 8)); iVar7 = iVar7 + 1) {
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

