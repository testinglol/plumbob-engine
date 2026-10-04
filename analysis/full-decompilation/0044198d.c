
undefined1 FUN_0044198d(void)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(uint *)(unaff_EBP + -0x40) = *(uint *)(unaff_EBP + -0x44) & 0xffff0000;
  *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x40) >> 0x10;
  *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf6) = *(undefined2 *)(unaff_EBP + -0x40);
  *(uint *)(unaff_EBP + -0x40) = *(uint *)(unaff_EBP + -0x44) & 0xffff;
  *(undefined2 *)(*(int *)(unaff_EBP + -0x3dc) + 0xf4) = *(undefined2 *)(unaff_EBP + -0x40);
  FUN_005da4c7(*(undefined4 *)(unaff_EBP + -0x58));
  if (*(char *)(unaff_EBP + 8) == '\0') {
    while( true ) {
      *(int *)(unaff_EBP + -900) = *(int *)(unaff_EBP + -0x3dc) + 0x58;
      *(undefined4 *)(unaff_EBP + -0x37c) = *(undefined4 *)(*(int *)(unaff_EBP + -900) + 4);
      *(undefined4 *)(unaff_EBP + -0x380) = **(undefined4 **)(unaff_EBP + -900);
      if (*(int *)(unaff_EBP + -0x37c) - *(int *)(unaff_EBP + -0x380) >> 1 == 0) break;
      *(undefined4 *)(unaff_EBP + -0x388) = *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x58);
      *(undefined2 *)(unaff_EBP + -0xcc) = **(undefined2 **)(unaff_EBP + -0x388);
      *(undefined4 *)(unaff_EBP + -0x38c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x58);
      FUN_004484c8(*(undefined4 *)(unaff_EBP + -0x38c));
      *(int *)(unaff_EBP + -0x3c4) = (int)*(short *)(unaff_EBP + -0xcc);
      *(undefined4 *)(unaff_EBP + -0x3b0) = 0;
      if (0 < *(int *)(unaff_EBP + -0x3c4)) {
        *(int *)(unaff_EBP + -0x3bc) = *(int *)(unaff_EBP + -0x3dc) + 0x18;
        *(undefined4 *)(unaff_EBP + -0x3b4) = *(undefined4 *)(*(int *)(unaff_EBP + -0x3bc) + 4);
        *(undefined4 *)(unaff_EBP + -0x3b8) = **(undefined4 **)(unaff_EBP + -0x3bc);
        if (*(uint *)(unaff_EBP + -0x3c4) <
            (*(int *)(unaff_EBP + -0x3b4) - *(int *)(unaff_EBP + -0x3b8) >> 2) + 1U) {
          *(undefined4 *)(unaff_EBP + -0x3c0) = *(undefined4 *)(*(int *)(unaff_EBP + -0x3dc) + 0x18)
          ;
          *(undefined4 *)(unaff_EBP + -0x3b0) =
               *(undefined4 *)(*(int *)(unaff_EBP + -0x3c0) + -4 + *(int *)(unaff_EBP + -0x3c4) * 4)
          ;
        }
      }
      *(undefined4 *)(unaff_EBP + -0xd0) = *(undefined4 *)(unaff_EBP + -0x3b0);
      if (*(int *)(unaff_EBP + -0xd0) != 0) {
        if (*(short *)(*(int *)(*(int *)(unaff_EBP + -0xd0) + 0x118) + 0x14) != 0) {
          uVar2 = FUN_006359f2(*(undefined4 *)(unaff_EBP + -0xd0),0,&cXObject::RTTI_Type_Descriptor,
                               &cXMTObject::RTTI_Type_Descriptor,0);
          *(undefined4 *)(unaff_EBP + -0xd4) = uVar2;
          if ((*(int *)(unaff_EBP + -0xd4) != 0) && (cVar1 = FUN_00423481(), cVar1 != '\0')) {
            FUN_0042349d();
          }
        }
        FUN_0044127f(*(undefined4 *)(unaff_EBP + -0xcc));
      }
    }
    if ((*(char *)(*(int *)(unaff_EBP + -0x3dc) + 0x12) != '\0') &&
       (*(undefined4 *)(unaff_EBP + -0x3c8) =
             *(undefined4 *)(*(int *)(*(int *)(unaff_EBP + -0x3dc) + 0x7c) + 0x98),
       *(int *)(unaff_EBP + -0x3c8) % 0x28 == 0)) {
      *(undefined4 *)(unaff_EBP + -0x3cc) = *(undefined4 *)(DAT_006e486c + 0x24);
      FUN_0042004f();
      *(undefined1 *)(*(int *)(unaff_EBP + -0x3dc) + 0x12) = 0;
    }
  }
  uVar2 = FUN_00445724();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  if (*(int *)(unaff_EBP + -0x14) == 0) {
    FUN_00445541();
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x3d0) = *(undefined4 *)(DAT_006e486c + 0x1c);
    cVar1 = FUN_004074bc();
    if (((cVar1 == '\x01') && (DAT_006e4f14 == 0)) &&
       (*(short *)(*(int *)(unaff_EBP + -0x14) + 0x5cc) != 0)) {
      FUN_00445541();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0x1c);
}

