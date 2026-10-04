
undefined4 FUN_00487563(void)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  int extraout_ECX;
  int unaff_EBP;
  int iVar10;
  TypeDescriptor *pTStack_40;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  iVar5 = FUN_004cf4ed();
  *(int *)(unaff_EBP + -0x2c) = iVar5;
  if (iVar5 == 0) {
    *(undefined4 *)(unaff_EBP + -0x2c) = 1;
  }
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  uVar6 = FUN_0046d9e5();
  *(undefined4 *)(unaff_EBP + -0x38) = uVar6;
  iVar5 = *(int *)(extraout_ECX + 0x3c);
  iVar7 = *(int *)(iVar5 + 400);
  *(int *)(unaff_EBP + -0x14) = iVar7;
  if (iVar7 == 0) {
    *(int *)(unaff_EBP + -0x14) = iVar5;
  }
  if (*(int *)(unaff_EBP + -0x14) != 0) {
    do {
      iVar5 = *(int *)(unaff_EBP + -0x14);
      cVar4 = *(char *)(iVar5 + 0xfc);
      cVar1 = *(char *)(iVar5 + 0xfd);
      *(char *)(unaff_EBP + -0x1c) = cVar4;
      *(char *)(unaff_EBP + -0x1b) = cVar1;
      *(undefined1 *)(unaff_EBP + -0x1a) = *(undefined1 *)(iVar5 + 0xfe);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (cVar4 < '\x01') goto LAB_0048798e;
      iVar10 = (int)cVar4;
      iVar7 = *(int *)(DAT_006e54dc + 0x10) + -1;
      if (((iVar7 <= iVar10) || (cVar1 < '\x01')) ||
         (*(int *)(unaff_EBP + -0x34) = (int)cVar1, iVar7 <= cVar1)) goto LAB_0048798e;
      pTStack_40 = &cXCursorObject::RTTI_Type_Descriptor;
      iVar5 = FUN_006359f2(iVar5,0,&cXMTObject::RTTI_Type_Descriptor);
      iVar5 = *(int *)(iVar5 + 0x1ac);
      if (iVar5 == 0) goto LAB_0048798e;
      *(char *)(unaff_EBP + -0x18) = cVar4;
      *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(unaff_EBP + -0x1b);
      *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(unaff_EBP + -0x1a);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      pTStack_40 = (TypeDescriptor *)0x48766e;
      FUN_00434ffd();
      uVar2 = *(ushort *)(iVar5 + 0x9e);
      if (((uVar2 & 1) == 0) &&
         (*(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x20 +
                                               *(char *)(unaff_EBP + -0x1a) * 4) + 0xc) + iVar10 * 4
                             ) + *(int *)(unaff_EBP + -0x34) * 2) != 0)) {
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
        pTStack_40 = (TypeDescriptor *)0x4876a8;
        iVar5 = FUN_004a15df();
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar5;
        pTStack_40 = (TypeDescriptor *)0x4876b4;
        cVar4 = FUN_0048941c();
        if (cVar4 != '\0') goto LAB_004876b9;
LAB_00487731:
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(undefined4 *)(unaff_EBP + -0x30) = 1;
        break;
      }
LAB_004876b9:
      if ((((uVar2 & 0x200) == 0) &&
          (*(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x20 +
                                                *(char *)(unaff_EBP + -0x1a) * 4) + 0xc) +
                              iVar10 * 4) + *(int *)(unaff_EBP + -0x34) * 2) == 0)) &&
         ('\x01' < *(char *)(unaff_EBP + -0x1a))) {
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 1;
        pTStack_40 = (TypeDescriptor *)0x4876f4;
        iVar5 = FUN_004a15df();
        *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar5;
        if (*(int *)(*(int *)(unaff_EBP + -0x20) + 0x90) + *(int *)(unaff_EBP + -0x24) <=
            *(int *)(unaff_EBP + -0x38)) {
          pTStack_40 = (TypeDescriptor *)0x487711;
          cVar4 = FUN_004892c1();
          if (cVar4 != '\0') goto LAB_00487716;
        }
        goto LAB_00487731;
      }
LAB_00487716:
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar5 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x18c);
      *(int *)(unaff_EBP + -0x14) = iVar5;
    } while (iVar5 != 0);
    if (*(int *)(unaff_EBP + -0x28) != 0) {
      if (0 < *(int *)(unaff_EBP + -0x30)) {
LAB_0048798e:
        uVar6 = 0;
        goto LAB_0048797f;
      }
      pTStack_40 = (TypeDescriptor *)0x487757;
      puVar8 = operator_new(0x34);
      *(undefined4 **)(unaff_EBP + -0x38) = puVar8;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (puVar8 == (undefined4 *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x28) = 0;
      }
      else {
        FUN_00492f28();
        *(undefined1 *)(unaff_EBP + -4) = 3;
        pTStack_40 = (TypeDescriptor *)0x48777f;
        FUN_0055e4e2();
        uVar6 = *(undefined4 *)(unaff_EBP + -0x20);
        *puVar8 = &PTR__scalar_deleting_destructor__00667d4c;
        puVar8[0xc] = uVar6;
        *(undefined4 **)(unaff_EBP + -0x28) = puVar8;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar5 = *(int *)(*(int *)(unaff_EBP + -0x20) + 0x3c);
      iVar7 = *(int *)(iVar5 + 400);
      *(int *)(unaff_EBP + -0x14) = iVar7;
      if (iVar7 == 0) {
        *(int *)(unaff_EBP + -0x14) = iVar5;
      }
      iVar5 = *(int *)(unaff_EBP + -0x14);
      while (iVar5 != 0) {
        iVar5 = *(int *)(unaff_EBP + -0x14);
        cVar4 = *(char *)(iVar5 + 0xfe);
        *(undefined1 *)(unaff_EBP + -0x1c) = *(undefined1 *)(iVar5 + 0xfc);
        *(char *)(unaff_EBP + -0x1a) = cVar4;
        *(undefined1 *)(unaff_EBP + -0x1b) = *(undefined1 *)(iVar5 + 0xfd);
        pTStack_40 = &cXCursorObject::RTTI_Type_Descriptor;
        *(undefined4 *)(unaff_EBP + -4) = 4;
        iVar5 = FUN_006359f2(iVar5,0,&cXMTObject::RTTI_Type_Descriptor);
        iVar5 = *(int *)(iVar5 + 0x1ac);
        if (iVar5 == 0) goto LAB_0048798e;
        *(char *)(unaff_EBP + -0x16) = cVar4;
        *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(unaff_EBP + -0x1b);
        *(undefined1 *)(unaff_EBP + -4) = 5;
        pTStack_40 = (TypeDescriptor *)0x48782b;
        FUN_00434ffd();
        uVar9 = (uint)*(short *)(iVar5 + 0x9e);
        *(uint *)(unaff_EBP + -0x34) = uVar9;
        if (((uVar9 & 1) == 0) &&
           (sVar3 = *(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x20 + cVar4 * 4) + 0xc) +
                                       *(char *)(unaff_EBP + -0x1c) * 4) +
                              *(char *)(unaff_EBP + -0x1b) * 2), sVar3 != 0)) {
          pTStack_40 = (TypeDescriptor *)0x48786c;
          uVar6 = FUN_004a15df();
          *(undefined4 *)(unaff_EBP + -0x38) = uVar6;
          __ftol();
          pTStack_40 = (TypeDescriptor *)0x0;
          FUN_0048864d(unaff_EBP + -0x18,sVar3);
          *(TypeDescriptor ***)(unaff_EBP + -0x38) = &pTStack_40;
          FUN_00461b74(unaff_EBP + -0x18);
          FUN_00487992();
          DAT_006e5780 = 1;
          pTStack_40 = (TypeDescriptor *)0x4878c3;
          FUN_004a6a15();
          pTStack_40 = (TypeDescriptor *)0x4878cd;
          FUN_00492bb0();
        }
        if ((((*(byte *)(unaff_EBP + -0x33) & 2) == 0) &&
            (*(short *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x20 + cVar4 * 4) + 0xc) +
                                *(char *)(unaff_EBP + -0x1c) * 4) + *(char *)(unaff_EBP + -0x1b) * 2
                       ) == 0)) && ('\x01' < cVar4)) {
          pTStack_40 = (TypeDescriptor *)0x48790d;
          FUN_004a15df();
          pTStack_40 = (TypeDescriptor *)0x0;
          FUN_0048864d(unaff_EBP + -0x18,0);
          *(TypeDescriptor ***)(unaff_EBP + -0x38) = &pTStack_40;
          FUN_00461b74(unaff_EBP + -0x18);
          FUN_00487992();
          DAT_006e5780 = 1;
          pTStack_40 = (TypeDescriptor *)0x48794d;
          FUN_004a6a15();
          pTStack_40 = (TypeDescriptor *)0x487957;
          FUN_00492bb0();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        iVar5 = *(int *)(*(int *)(unaff_EBP + -0x14) + 0x18c);
        *(int *)(unaff_EBP + -0x14) = iVar5;
      }
      pTStack_40 = (TypeDescriptor *)0x48797d;
      (**(code **)(**(int **)(*(int *)(unaff_EBP + -0x20) + 0x30) + 0x14))();
    }
  }
  uVar6 = 1;
LAB_0048797f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

