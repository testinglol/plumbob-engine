
void FUN_004207e3(void)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  void *pvVar6;
  undefined4 extraout_ECX;
  char *pcVar7;
  UINT_PTR uIDNewItem;
  int iVar8;
  int unaff_EBP;
  undefined4 *puVar9;
  UINT uFlags;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x20) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x35c,0,0x100);
  *(undefined ***)(unaff_EBP + -0x368) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x144,0,0x100);
  *(undefined ***)(unaff_EBP + -0x150) = &PTR_FUN_00666524;
  FUN_0046f824(unaff_EBP + -0x250,0,0x100);
  *(undefined ***)(unaff_EBP + -0x25c) = &PTR_FUN_00666524;
  FUN_0046f847(*(undefined4 *)(unaff_EBP + 8),0xffffffff);
  uVar3 = (uint)*(ushort *)(unaff_EBP + -0x254);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  if (uVar3 != 0) {
    *(undefined4 *)(unaff_EBP + 8) = 1;
    do {
      pcVar7 = (char *)(*(int *)(unaff_EBP + -600) + *(int *)(unaff_EBP + -0x10));
      cVar1 = *pcVar7;
      *(char *)(unaff_EBP + -0x14) = cVar1;
      if (cVar1 == '[') {
        if (((int)uVar3 <= *(int *)(unaff_EBP + 8)) || (pcVar7[1] != '[')) goto LAB_004208d3;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      }
      else if (((cVar1 == ']') && (*(int *)(unaff_EBP + 8) < (int)uVar3)) && (pcVar7[1] == ']')) {
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      }
      else {
LAB_004208d3:
        FUN_0046fa24(*(undefined4 *)(unaff_EBP + -0x14));
      }
      uVar3 = (uint)*(ushort *)(unaff_EBP + -0x254);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < (int)uVar3);
  }
  FUN_0046f824(unaff_EBP + -0x468,0,0x100);
  iVar8 = 0;
  *(undefined ***)(unaff_EBP + -0x474) = &PTR_FUN_00666524;
  if (*(short *)(unaff_EBP + -0x148) != 0) {
    do {
      cVar1 = *(char *)(*(int *)(unaff_EBP + -0x14c) + iVar8);
      *(char *)(unaff_EBP + -0x14) = cVar1;
      if (cVar1 == 0x2d) {
        if (iVar8 == 0) {
          *(undefined4 *)(unaff_EBP + -0x18) = 1;
        }
LAB_0042094f:
        FUN_0046fa24(*(undefined4 *)(unaff_EBP + -0x14));
      }
      else {
        if (cVar1 != 0xc9) goto LAB_0042094f;
        FUN_0046f847(&DAT_006c220c,0xffffffff);
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(uint)*(ushort *)(unaff_EBP + -0x148));
  }
  iVar8 = *(int *)(unaff_EBP + -0x20);
  uIDNewItem = (int)*(short *)(iVar8 + 0xe) + 1;
  *(UINT_PTR *)(unaff_EBP + 8) = uIDNewItem;
  if (*(short *)(unaff_EBP + -0x360) != 0) {
    FUN_00401168();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined4 *)(unaff_EBP + -0x40) = 0;
    *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x364);
    *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x364);
    *(undefined4 *)(unaff_EBP + -0x3c) = 1;
    *(undefined ***)(unaff_EBP + -0x44) = &PTR_LAB_00666a04;
    FUN_0040128c(unaff_EBP + -0x44);
    iVar4 = FUN_00401502(s_itemnum_006c2204);
    if (iVar4 != 0) {
      iVar4 = FUN_00635f62(iVar4);
      if (iVar4 != 0) {
        *(int *)(unaff_EBP + 8) = iVar4;
      }
    }
    iVar4 = FUN_00401502(s_break_006c21fc);
    if (iVar4 != 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
    }
    iVar4 = FUN_00401502(s_title_006c21f4);
    if (iVar4 != 0) {
      FUN_0046f8cb(iVar4);
      *(undefined4 *)(unaff_EBP + -0x1c) = 1;
    }
    iVar4 = FUN_00401502(s_submenu_006c21ec);
    if (iVar4 != 0) {
      uVar5 = FUN_00635f62(iVar4);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar5;
      pvVar6 = operator_new(0x128);
      *(void **)(unaff_EBP + 8) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar6 == (void *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(unaff_EBP + -0x14c);
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar8 + 0x124);
        FUN_0046f824((int)pvVar6 + 0x24,0,0x100);
        uVar5 = *(undefined4 *)(unaff_EBP + -0x1c);
        *(undefined ***)((int)pvVar6 + 0x18) = &PTR_FUN_00666524;
        puVar9 = *(undefined4 **)(unaff_EBP + 8);
        uVar2 = *(undefined4 *)(unaff_EBP + -0x18);
        *puVar9 = &PTR_FUN_006669f4;
        FUN_004201ab(*(undefined4 *)(unaff_EBP + -0x14),0x4d454e55,uVar2,uVar5);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_00420b1a(puVar9);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_004011d4();
      goto LAB_00420afb;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004011d4();
    uIDNewItem = *(UINT_PTR *)(unaff_EBP + 8);
  }
  uFlags = 0;
  if (*(short *)(unaff_EBP + -0x18) != 0) {
    uFlags = 0x800;
  }
  if (*(short *)(unaff_EBP + -0x1c) == 0) {
    if ((0 < *(short *)(iVar8 + 0xe)) && ((int)*(short *)(iVar8 + 0xe) % 0x1e == 0)) {
      uFlags = uFlags | 0x20;
    }
    AppendMenuA(*(HMENU *)(iVar8 + 4),uFlags,uIDNewItem,*(LPCSTR *)(unaff_EBP + -0x470));
    *(short *)(iVar8 + 0xe) = *(short *)(iVar8 + 0xe) + 1;
  }
LAB_00420afb:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

