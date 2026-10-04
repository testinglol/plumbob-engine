
undefined1 FUN_0044322d(void)

{
  byte bVar1;
  short sVar2;
  undefined1 uVar3;
  short sVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0xb4) = extraout_ECX;
  *(int *)(unaff_EBP + -0x80) = (int)*(short *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x6c) = 0;
  if (0 < *(int *)(unaff_EBP + -0x80)) {
    *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0xb4) + 0x18;
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(*(int *)(unaff_EBP + -0x78) + 4);
    *(undefined4 *)(unaff_EBP + -0x74) = **(undefined4 **)(unaff_EBP + -0x78);
    if (*(uint *)(unaff_EBP + -0x80) <
        (*(int *)(unaff_EBP + -0x70) - *(int *)(unaff_EBP + -0x74) >> 2) + 1U) {
      *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 0x18);
      *(undefined4 *)(unaff_EBP + -0x6c) =
           *(undefined4 *)(*(int *)(unaff_EBP + -0x7c) + -4 + *(int *)(unaff_EBP + -0x80) * 4);
    }
  }
  uVar5 = FUN_006359f2(*(undefined4 *)(unaff_EBP + -0x6c),0,&cXObject::RTTI_Type_Descriptor,
                       &cXPerson::RTTI_Type_Descriptor,0);
  *(undefined4 *)(unaff_EBP + -0x54) = uVar5;
  if (*(int *)(unaff_EBP + -0x54) == 0) {
    uVar3 = 0;
  }
  else {
    if (*(short *)(unaff_EBP + 0xc) != 0) {
      *(int *)(unaff_EBP + -0x98) = (int)*(short *)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -0x84) = 0;
      if (0 < *(int *)(unaff_EBP + -0x98)) {
        *(int *)(unaff_EBP + -0x90) = *(int *)(unaff_EBP + -0xb4) + 0x18;
        *(undefined4 *)(unaff_EBP + -0x88) = *(undefined4 *)(*(int *)(unaff_EBP + -0x90) + 4);
        *(undefined4 *)(unaff_EBP + -0x8c) = **(undefined4 **)(unaff_EBP + -0x90);
        if (*(uint *)(unaff_EBP + -0x98) <
            (*(int *)(unaff_EBP + -0x88) - *(int *)(unaff_EBP + -0x8c) >> 2) + 1U) {
          *(undefined4 *)(unaff_EBP + -0x94) = *(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 0x18);
          *(undefined4 *)(unaff_EBP + -0x84) =
               *(undefined4 *)(*(int *)(unaff_EBP + -0x94) + -4 + *(int *)(unaff_EBP + -0x98) * 4);
        }
      }
      *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x84);
      if (*(int *)(unaff_EBP + -100) == 0) {
        uVar3 = 0;
        goto LAB_004434b6;
      }
      uVar5 = FUN_00457ccc();
      *(undefined4 *)(unaff_EBP + -0x58) = uVar5;
    }
    if (*(int *)(unaff_EBP + -0x58) == 0) {
      uVar3 = 0;
    }
    else {
      if (0 < *(short *)(unaff_EBP + 0x10)) {
        sVar2 = *(short *)(unaff_EBP + 0x10);
        sVar4 = FUN_0046fbe5(0xffffffff);
        if (sVar2 < sVar4) {
          if (*(short *)(*(int *)(unaff_EBP + -0xb4) + 0x80) == 0) {
            uVar3 = 0;
          }
          else {
            *(undefined2 *)(unaff_EBP + -0x60) = *(undefined2 *)(unaff_EBP + 0xc);
            *(undefined2 *)(unaff_EBP + -0x5e) = *(undefined2 *)(unaff_EBP + 0x10);
            bVar1 = *(byte *)(unaff_EBP + 0x14);
            *(ushort *)(unaff_EBP + -0x5c) =
                 -(((ushort)bVar1 - (ushort)bVar1) - (ushort)(bVar1 != 0));
            *(undefined2 *)(unaff_EBP + -0x5a) = 0;
            *(int *)(unaff_EBP + -0xb0) = (int)*(short *)(*(int *)(unaff_EBP + -0xb4) + 0x80);
            *(undefined4 *)(unaff_EBP + -0x9c) = 0;
            if (0 < *(int *)(unaff_EBP + -0xb0)) {
              *(int *)(unaff_EBP + -0xa8) = *(int *)(unaff_EBP + -0xb4) + 0x18;
              *(undefined4 *)(unaff_EBP + -0xa0) = *(undefined4 *)(*(int *)(unaff_EBP + -0xa8) + 4);
              *(undefined4 *)(unaff_EBP + -0xa4) = **(undefined4 **)(unaff_EBP + -0xa8);
              if (*(uint *)(unaff_EBP + -0xb0) <
                  (*(int *)(unaff_EBP + -0xa0) - *(int *)(unaff_EBP + -0xa4) >> 2) + 1U) {
                *(undefined4 *)(unaff_EBP + -0xac) =
                     *(undefined4 *)(*(int *)(unaff_EBP + -0xb4) + 0x18);
                *(undefined4 *)(unaff_EBP + -0x9c) =
                     *(undefined4 *)
                      (*(int *)(unaff_EBP + -0xac) + -4 + *(int *)(unaff_EBP + -0xb0) * 4);
              }
            }
            FUN_0041f010(*(undefined4 *)(unaff_EBP + -0x54),*(undefined4 *)(unaff_EBP + -0x9c),0,100
                        );
            *(undefined4 *)(unaff_EBP + -4) = 0;
            FUN_0041f0db(unaff_EBP + -0x60);
            FUN_0045d377(unaff_EBP + -0x50);
            *(undefined1 *)(unaff_EBP + -0x68) = 1;
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            FUN_005b8770();
            uVar3 = *(undefined1 *)(unaff_EBP + -0x68);
          }
          goto LAB_004434b6;
        }
      }
      uVar3 = 0;
    }
  }
LAB_004434b6:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

