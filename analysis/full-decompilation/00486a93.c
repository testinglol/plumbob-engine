
void FUN_00486a93(void)

{
  short sVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar4 = FUN_00492b10(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  *(undefined4 *)(extraout_ECX + 0x58) = 0;
  iVar5 = FUN_006359f2(uVar4,0,&cXObject::RTTI_Type_Descriptor,&cXMTObject::RTTI_Type_Descriptor,0);
  if (iVar5 != 0) {
    *(undefined4 *)(extraout_ECX + 0x58) = *(undefined4 *)(iVar5 + 0x1a8);
  }
  puVar2 = PTR_s_Tile_Cursor_006c5e3c;
  if (*(int *)(unaff_EBP + -0x10) != 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x110);
    uVar4 = FUN_0043ac74(puVar2);
    uVar4 = FUN_00492b05(*(undefined4 *)(unaff_EBP + 8),uVar4,*(undefined4 *)(unaff_EBP + -0x10));
    uVar4 = FUN_00421619(uVar4);
    uVar4 = FUN_00492b10(uVar4,0,&cXObject::RTTI_Type_Descriptor,
                         &cXCursorObject::RTTI_Type_Descriptor,0);
    iVar5 = FUN_006359f2(uVar4);
    *(int *)(extraout_ECX + 0x3c) = iVar5;
    if (iVar5 != 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar5 + 0xf4);
      iVar3 = DAT_006e54d8;
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar5 + 0xf8);
      FUN_0047bd91(unaff_EBP + -0x14,unaff_EBP + -0x18,*(undefined4 *)(iVar3 + 0x84),0x400);
      uVar4 = FUN_00492b26();
      uVar6 = FUN_004a6a46(unaff_EBP + -0x18,uVar4);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      uVar4 = 0;
      sVar1 = *(short *)(unaff_EBP + 0x14);
      *(int *)(extraout_ECX + 0x50) =
           (int)*(short *)(unaff_EBP + 0x16) - (int)*(short *)(unaff_EBP + -0xe);
      *(int *)(extraout_ECX + 0x54) = (int)sVar1 - (int)(short)uVar6;
      iVar5 = *(int *)(*(int *)(extraout_ECX + 0x3c) + 0x1ac);
      if (iVar5 != 0) {
        FUN_004341a6(0);
        uVar4 = *(undefined4 *)(iVar5 + 0x11c);
      }
      FUN_00487c19(uVar4);
      pvVar7 = operator_new(0x88);
      *(void **)(unaff_EBP + 0x14) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar7 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = FUN_0048bb59(*(undefined4 *)(unaff_EBP + 8),1,0,extraout_ECX);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(extraout_ECX + 0x30) = iVar5;
      if (iVar5 != 0) {
        *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 1;
      }
      *(undefined4 *)(extraout_ECX + 0x90) = 0;
      *(undefined4 *)(extraout_ECX + 0x20) = 0;
    }
  }
  FUN_00486e21();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

