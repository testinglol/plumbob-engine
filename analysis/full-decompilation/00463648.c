
void FUN_00463648(void)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  char cVar5;
  int extraout_ECX;
  int iVar6;
  int unaff_EBP;
  undefined4 *puVar7;
  undefined4 auStack_a0 [5];
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  TypeDescriptor *pTStack_80;
  TypeDescriptor *pTStack_7c;
  int *piStack_78;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = DAT_006e54dc;
  puVar4 = (undefined4 *)(unaff_EBP + -0x48);
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar6 = *(int *)(extraout_ECX + 400);
  *(int *)(unaff_EBP + -0x10) = iVar6;
  if (iVar6 == 0) {
    *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  }
  iVar6 = *(int *)(unaff_EBP + -0x10);
  while (iVar6 != 0) {
    if ((*(byte *)(unaff_EBP + -0x20) & 0x10) != 0) {
      puVar4 = (undefined4 *)(unaff_EBP + -0x48);
      for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    piStack_78 = (int *)0x0;
    pTStack_7c = &cXPortal::RTTI_Type_Descriptor;
    pTStack_80 = &cXMTObject::RTTI_Type_Descriptor;
    uStack_84 = 0;
    uStack_88 = *(undefined4 *)(unaff_EBP + -0x10);
    uStack_8c = 0x4636af;
    iVar6 = FUN_006359f2();
    if (*(short *)(*(int *)(iVar6 + 0x118) + 0x5c) != 0) {
      piStack_78 = (int *)0x4636cc;
      iVar3 = FUN_00435968();
      *(int *)(unaff_EBP + -0x1c) = iVar3;
      if (iVar3 != 0) {
        iVar3 = *(int *)(iVar6 + 0xf8);
        *(char *)(unaff_EBP + -0x12) = (char)*(undefined4 *)(iVar6 + 0x110);
        iVar6 = *(int *)(iVar6 + 0xf4);
        cVar2 = (char)(iVar3 >> 4);
        *(char *)(unaff_EBP + -0x14) = cVar2;
        cVar5 = (char)(iVar6 >> 4);
        *(char *)(unaff_EBP + -0x13) = cVar5;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (((('\0' < cVar2) &&
             (iVar6 = *(int *)(*(int *)(unaff_EBP + -0x18) + 0x10) + -1, cVar2 < iVar6)) &&
            ('\0' < cVar5)) && (cVar5 < iVar6)) {
          piStack_78 = (int *)(unaff_EBP + -0x14);
          pTStack_7c = (TypeDescriptor *)(unaff_EBP + -0x74);
          pTStack_80 = (TypeDescriptor *)0x46372b;
          puVar4 = (undefined4 *)FUN_00479737();
          piStack_78 = *(int **)(unaff_EBP + -0x1c);
          puVar7 = (undefined4 *)(unaff_EBP + -0x48);
          for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar7 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar7 = puVar7 + 1;
          }
          pTStack_7c = (TypeDescriptor *)0x1;
          pTStack_80 = (TypeDescriptor *)0x463742;
          FUN_004633e3();
          *(undefined4 **)(unaff_EBP + -0x1c) = auStack_a0;
          puVar4 = (undefined4 *)(unaff_EBP + -0x48);
          puVar7 = auStack_a0;
          for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar7 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar7 = puVar7 + 1;
          }
          FUN_00479954(unaff_EBP + -0x14);
          piStack_78 = *(int **)(extraout_ECX + 0x110);
          pTStack_7c = (TypeDescriptor *)0x463769;
          FUN_00540a5b();
          pTStack_7c = (TypeDescriptor *)0x463770;
          FUN_00540eb1();
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
      }
    }
    iVar6 = *(int *)(*(int *)(unaff_EBP + -0x10) + 0x18c);
    *(int *)(unaff_EBP + -0x10) = iVar6;
  }
  pTStack_7c = (TypeDescriptor *)0x46379a;
  piStack_78 = (int *)(extraout_ECX + 0xf4);
  cVar2 = FUN_00422665();
  if (cVar2 == '\0') {
    uVar1 = *(undefined4 *)(extraout_ECX + 0x110);
    *(char *)(unaff_EBP + -0x14) = (char)(*(int *)(extraout_ECX + 0xf8) >> 4);
    *(char *)(unaff_EBP + -0x13) = (char)(*(int *)(extraout_ECX + 0xf4) >> 4);
    *(char *)(unaff_EBP + -0x12) = (char)uVar1;
    iVar6 = DAT_006e54d8;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    piStack_78 = *(int **)(iVar6 + 0x84);
    pTStack_7c = (TypeDescriptor *)0x4637cf;
    FUN_00434ffd();
    piStack_78 = (int *)(unaff_EBP + -0x14);
    pTStack_7c = (TypeDescriptor *)0x4637d8;
    FUN_00476b8f();
    *(undefined1 *)(unaff_EBP + -4) = 0;
  }
  piStack_78 = *(int **)(unaff_EBP + 8);
  pTStack_7c = (TypeDescriptor *)0x4637e7;
  FUN_00422db9();
  piStack_78 = *(int **)(extraout_ECX + 0xdc);
  pTStack_7c = (TypeDescriptor *)0x4637f2;
  FUN_004639d2();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

