
undefined4 FUN_00482351(void)

{
  char cVar1;
  char cVar2;
  short sVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar4 = *(char *)(unaff_EBP + 8);
  cVar1 = *(char *)(unaff_EBP + 0xc);
  cVar2 = *(char *)(unaff_EBP + 0x10);
  iVar6 = *(int *)(*(int *)(unaff_EBP + 0x18) + 0x1c);
  *(int *)(unaff_EBP + -0x14) = iVar6;
  *(char *)(unaff_EBP + -0x10) = cVar4;
  *(char *)(unaff_EBP + -0xf) = cVar1;
  *(char *)(unaff_EBP + -0xe) = cVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)(unaff_EBP + 0xb) = 0;
  sVar5 = *(short *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x28 + cVar2 * 4) + 0xc) + cVar4 * 4) +
                    cVar1 * 2);
  sVar3 = *(short *)(unaff_EBP + 0x14);
  if ((sVar5 == sVar3) || (sVar5 == -5)) {
LAB_0048244f:
    cVar4 = FUN_004790bc(unaff_EBP + -0x10);
    if (cVar4 != '\x01') {
LAB_00482490:
      uVar7 = 1;
      goto LAB_00482496;
    }
    FUN_0043f371(*DAT_006e486c,unaff_EBP + -0x10,0);
    while (*(int *)(unaff_EBP + -0x1c) != 0) {
      if ((*(ushort *)(*(int *)(unaff_EBP + -0x1c) + 0x5a) & 0x1000) != 0) goto LAB_00482490;
      FUN_0043f3b9();
    }
  }
  else {
    *(char *)(unaff_EBP + 0x14) = cVar4;
    *(char *)(unaff_EBP + 0x15) = cVar1;
    *(char *)(unaff_EBP + 0x16) = cVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0043f371(*(undefined4 *)(unaff_EBP + 0x18),unaff_EBP + 0x14,0);
    iVar6 = *(int *)(unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    if (iVar6 != 0) {
      do {
        if (*(short *)(*(int *)(iVar6 + 0x118) + 0x12) == 8) {
          FUN_00457da4();
          sVar5 = FUN_004561a0(0xf);
          if (((sVar5 != 0) &&
              (iVar6 = FUN_006359f2(*(undefined4 *)(unaff_EBP + -0x1c),0,
                                    &cXObject::RTTI_Type_Descriptor,&cXPortal::RTTI_Type_Descriptor,
                                    0), iVar6 != 0)) &&
             (iVar6 = FUN_00463804(), *(short *)(iVar6 + 0x84) == sVar3)) {
            *(undefined1 *)(unaff_EBP + 0xb) = 1;
          }
        }
        FUN_0043f3b9();
        iVar6 = *(int *)(unaff_EBP + -0x1c);
      } while (iVar6 != 0);
      if (*(char *)(unaff_EBP + 0xb) != '\0') goto LAB_0048244f;
    }
  }
  uVar7 = 0;
LAB_00482496:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

