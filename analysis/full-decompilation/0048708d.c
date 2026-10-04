
void FUN_0048708d(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (DAT_006e576c == 0) {
    FUN_00486fb2();
  }
  if (*(char *)((int)extraout_ECX + 0x75) != '\0') {
    (**(code **)(*extraout_ECX + 0x18))();
    FUN_00492beb();
    if (extraout_ECX[0x11] != extraout_ECX[0x12]) {
      iVar2 = FUN_004227a9();
      extraout_ECX[0x10] = iVar2;
    }
    extraout_ECX[0x12] = extraout_ECX[0x11];
    sVar1 = *(short *)(*(int *)(extraout_ECX[0x11] + 0x60) + 0x24);
    iVar2 = FUN_0046d9e5();
    if (sVar1 <= iVar2) {
      if (extraout_ECX[0xd] == 5) {
        uVar4 = 1;
      }
      else {
        uVar4 = FUN_00492b26();
      }
      uVar3 = FUN_0043ac74(PTR_s_Tile_Cursor_006c5e3c);
      uVar4 = FUN_00492b05(extraout_ECX[0x11],uVar3,uVar4);
      uVar4 = FUN_004219b9(uVar4);
      uVar4 = FUN_00492b10(uVar4,0,&cXObject::RTTI_Type_Descriptor,
                           &cXCursorObject::RTTI_Type_Descriptor,0);
      iVar2 = FUN_006359f2(uVar4);
      extraout_ECX[0xf] = iVar2;
      if (iVar2 == 0) goto LAB_00487229;
      extraout_ECX[0x16] = 0;
      iVar2 = *(int *)(iVar2 + 0x1ac);
      FUN_004226ef(extraout_ECX[0x10]);
      if (iVar2 != 0) {
        uVar4 = FUN_00421e75();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
        pvVar5 = operator_new(0x88);
        *(void **)(unaff_EBP + -0x14) = pvVar5;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar5 == (void *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_0048bb59(*(undefined2 *)(iVar2 + 0xf0),0,*(undefined4 *)(unaff_EBP + -0x10),
                               extraout_ECX);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0xc] = iVar6;
        if (iVar6 != 0) {
          *(int *)(iVar6 + 8) = *(int *)(iVar6 + 8) + 1;
        }
        extraout_ECX[0x24] = *(int *)(unaff_EBP + -0x10);
        iVar6 = extraout_ECX[0xd];
        if (((iVar6 == 3) || (iVar6 == 4)) || (iVar6 == 5)) {
          (**(code **)(*extraout_ECX + 0x3c))();
        }
        FUN_00486ec8(*(undefined2 *)(iVar2 + 0xf0),0);
        *(undefined1 *)((int)extraout_ECX + 0x97) = 0;
        *(undefined1 *)(extraout_ECX + 0x26) = 0;
        extraout_ECX[0x28] = -0x10;
        extraout_ECX[0x27] = -0x10;
        extraout_ECX[0x2a] = -0x10;
        extraout_ECX[0x29] = -0x10;
        *(undefined1 *)((int)extraout_ECX + 0x95) = 0;
        *(undefined1 *)((int)extraout_ECX + 0x96) = 0;
      }
    }
  }
  FUN_00486e21();
LAB_00487229:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

