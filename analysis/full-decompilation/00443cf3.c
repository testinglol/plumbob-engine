
undefined4 FUN_00443cf3(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  char *pcVar5;
  undefined *puVar6;
  char *pcVar7;
  char *pcVar8;
  undefined *puVar9;
  undefined *puVar10;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0xa0) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x14) = DAT_006e54dc;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x10);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  while (*(int *)(unaff_EBP + -0x10) < 2) {
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    while (*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x18)) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      while (*(int *)(unaff_EBP + -0x20) < *(int *)(unaff_EBP + -0x18)) {
        *(undefined1 *)(unaff_EBP + -0x2c) = *(undefined1 *)(unaff_EBP + -0x1c);
        *(undefined1 *)(unaff_EBP + -0x2b) = *(undefined1 *)(unaff_EBP + -0x20);
        *(undefined1 *)(unaff_EBP + -0x2a) = *(undefined1 *)(unaff_EBP + -0x10);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        uVar1 = FUN_004325af(unaff_EBP + -0x2c);
        *(undefined2 *)(unaff_EBP + -0x28) = uVar1;
        if (*(short *)(unaff_EBP + -0x28) != 0) {
          *(int *)(unaff_EBP + -100) = (int)*(short *)(unaff_EBP + -0x28);
          *(undefined4 *)(unaff_EBP + -0x50) = 0;
          if (0 < *(int *)(unaff_EBP + -100)) {
            *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0xa0) + 0x18;
            *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(*(int *)(unaff_EBP + -0x5c) + 4);
            *(undefined4 *)(unaff_EBP + -0x58) = **(undefined4 **)(unaff_EBP + -0x5c);
            if (*(uint *)(unaff_EBP + -100) <
                (*(int *)(unaff_EBP + -0x54) - *(int *)(unaff_EBP + -0x58) >> 2) + 1U) {
              *(undefined4 *)(unaff_EBP + -0x60) =
                   *(undefined4 *)(*(int *)(unaff_EBP + -0xa0) + 0x18);
              *(undefined4 *)(unaff_EBP + -0x50) =
                   *(undefined4 *)
                    (*(int *)(unaff_EBP + -0x60) + -4 + *(int *)(unaff_EBP + -100) * 4);
            }
          }
          *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x50);
          if (*(int *)(unaff_EBP + -0x30) == 0) {
            pcVar7 = s_has_no_object_pointer_006c3c90;
            puVar6 = &DAT_006c0c28;
            iVar2 = (int)*(char *)(unaff_EBP + -0x2a);
            pcVar5 = s_in_grid_at_006c3c80;
            iVar3 = (int)*(short *)(unaff_EBP + -0x28);
            FUN_005bc69b(s_object_id_006c3c74);
            FUN_005bc69b(iVar3);
            FUN_005bc69b(pcVar5);
            FUN_005bc69b(iVar2);
            uVar4 = FUN_005bc69b(puVar6);
            FUN_00444296(uVar4);
            FUN_005bc69b(pcVar7);
            FUN_00432888(unaff_EBP + -0x2c,0);
          }
          else {
            *(int *)(unaff_EBP + -0x68) = *(int *)(unaff_EBP + -0x30) + 0xfc;
            *(undefined1 *)(unaff_EBP + -0x34) = **(undefined1 **)(unaff_EBP + -0x68);
            *(undefined1 *)(unaff_EBP + -0x33) = *(undefined1 *)(*(int *)(unaff_EBP + -0x68) + 1);
            *(undefined1 *)(unaff_EBP + -0x32) = *(undefined1 *)(*(int *)(unaff_EBP + -0x68) + 2);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            if (((*(char *)(unaff_EBP + -0x2c) == *(char *)(unaff_EBP + -0x34)) &&
                (*(char *)(unaff_EBP + -0x2b) == *(char *)(unaff_EBP + -0x33))) &&
               (*(char *)(unaff_EBP + -0x2a) == *(char *)(unaff_EBP + -0x32))) {
              *(undefined4 *)(unaff_EBP + -0xa4) = 0;
            }
            else {
              *(undefined4 *)(unaff_EBP + -0xa4) = 1;
            }
            if (*(char *)(unaff_EBP + -0xa4) != '\0') {
              puVar10 = &DAT_006c08dc;
              puVar9 = &DAT_006c0c28;
              iVar2 = (int)*(char *)(unaff_EBP + -0x2a);
              pcVar7 = s_but_is_in_the_grid_at_006c3cb8;
              puVar6 = &DAT_006c0c28;
              iVar3 = (int)*(char *)(unaff_EBP + -0x32);
              pcVar5 = s_has_location_006c3ca8;
              FUN_004442e5(&DAT_006fe545,*(undefined4 *)(unaff_EBP + -0x30),s_has_location_006c3ca8,
                           iVar3,&DAT_006c0c28,unaff_EBP + -0x34,s_but_is_in_the_grid_at_006c3cb8,
                           iVar2,&DAT_006c0c28,unaff_EBP + -0x2c,&DAT_006c08dc);
              FUN_005bc69b(pcVar5);
              FUN_005bc69b(iVar3);
              uVar4 = FUN_005bc69b(puVar6);
              FUN_00444296(uVar4);
              FUN_005bc69b(pcVar7);
              FUN_005bc69b(iVar2);
              uVar4 = FUN_005bc69b(puVar9);
              FUN_00444296(uVar4);
              FUN_005bc69b(puVar10);
              FUN_00432888(unaff_EBP + -0x2c,0);
            }
            *(undefined1 *)(unaff_EBP + -4) = 0;
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
      }
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  }
  uVar4 = *(undefined4 *)(*(int *)(unaff_EBP + -0xa0) + 0x30);
  *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
  while (*(int *)(unaff_EBP + -0x24) != 0) {
    *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x24) + 0xfc;
    *(undefined1 *)(unaff_EBP + -0x3c) = **(undefined1 **)(unaff_EBP + -0x74);
    *(undefined1 *)(unaff_EBP + -0x3b) = *(undefined1 *)(*(int *)(unaff_EBP + -0x74) + 1);
    *(undefined1 *)(unaff_EBP + -0x3a) = *(undefined1 *)(*(int *)(unaff_EBP + -0x74) + 2);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x24);
    while( true ) {
      iVar2 = FUN_004327c8();
      if (iVar2 == 0) break;
      uVar4 = FUN_004327c8();
      *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
    }
    if (*(int *)(unaff_EBP + -0x38) == *(int *)(unaff_EBP + -0x24)) {
      if ((((*(char *)(unaff_EBP + -0x3c) < '\x01') ||
           (*(int *)(*(int *)(unaff_EBP + -0x14) + 0x10) + -1 <= (int)*(char *)(unaff_EBP + -0x3c)))
          || (*(char *)(unaff_EBP + -0x3b) < '\x01')) ||
         (*(int *)(*(int *)(unaff_EBP + -0x14) + 0x10) + -1 <= (int)*(char *)(unaff_EBP + -0x3b))) {
        *(undefined1 *)(unaff_EBP + -0x7c) = 1;
      }
      else {
        *(undefined1 *)(unaff_EBP + -0x7c) = 0;
      }
      if (*(char *)(unaff_EBP + -0x7c) == '\0') {
        uVar1 = FUN_004325af(unaff_EBP + -0x3c);
        *(undefined2 *)(unaff_EBP + -0x44) = uVar1;
        *(undefined2 *)(unaff_EBP + -0x84) = *(undefined2 *)(*(int *)(unaff_EBP + -0x24) + 0xf0);
        if (*(short *)(unaff_EBP + -0x44) != *(short *)(unaff_EBP + -0x84)) {
          pcVar7 = s_but_grid_has_006c3c50;
          puVar6 = &DAT_006c0c28;
          iVar2 = (int)*(char *)(unaff_EBP + -0x3a);
          pcVar5 = s_is_at_006c3c6c;
          FUN_004442e5(&DAT_006fe545,*(undefined4 *)(unaff_EBP + -0x24),s_is_at_006c3c6c,iVar2,
                       &DAT_006c0c28,unaff_EBP + -0x3c,s_but_grid_has_006c3c50);
          FUN_005bc69b(pcVar5);
          FUN_005bc69b(iVar2);
          uVar4 = FUN_005bc69b(puVar6);
          FUN_00444296(uVar4);
          FUN_005bc69b(pcVar7);
          *(int *)(unaff_EBP + -0x9c) = (int)*(short *)(unaff_EBP + -0x44);
          *(undefined4 *)(unaff_EBP + -0x88) = 0;
          if (0 < *(int *)(unaff_EBP + -0x9c)) {
            *(int *)(unaff_EBP + -0x94) = *(int *)(unaff_EBP + -0xa0) + 0x18;
            *(undefined4 *)(unaff_EBP + -0x8c) = *(undefined4 *)(*(int *)(unaff_EBP + -0x94) + 4);
            *(undefined4 *)(unaff_EBP + -0x90) = **(undefined4 **)(unaff_EBP + -0x94);
            if (*(uint *)(unaff_EBP + -0x9c) <
                (*(int *)(unaff_EBP + -0x8c) - *(int *)(unaff_EBP + -0x90) >> 2) + 1U) {
              *(undefined4 *)(unaff_EBP + -0x98) =
                   *(undefined4 *)(*(int *)(unaff_EBP + -0xa0) + 0x18);
              *(undefined4 *)(unaff_EBP + -0x88) =
                   *(undefined4 *)
                    (*(int *)(unaff_EBP + -0x98) + -4 + *(int *)(unaff_EBP + -0x9c) * 4);
            }
          }
          *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x88);
          if (*(int *)(unaff_EBP + -0x48) == 0) {
            FUN_005bc69b((int)*(short *)(unaff_EBP + -0x44));
          }
          else {
            FUN_004442e5(&DAT_006fe545,*(undefined4 *)(unaff_EBP + -0x48));
          }
          FUN_005bc69b(s_there_006c3c48);
        }
      }
    }
    else {
      *(int *)(unaff_EBP + -0x78) = *(int *)(unaff_EBP + -0x38) + 0xfc;
      *(undefined1 *)(unaff_EBP + -0x40) = **(undefined1 **)(unaff_EBP + -0x78);
      *(undefined1 *)(unaff_EBP + -0x3f) = *(undefined1 *)(*(int *)(unaff_EBP + -0x78) + 1);
      *(undefined1 *)(unaff_EBP + -0x3e) = *(undefined1 *)(*(int *)(unaff_EBP + -0x78) + 2);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      if (((*(char *)(unaff_EBP + -0x3c) == *(char *)(unaff_EBP + -0x40)) &&
          (*(char *)(unaff_EBP + -0x3b) == *(char *)(unaff_EBP + -0x3f))) &&
         (*(char *)(unaff_EBP + -0x3a) == *(char *)(unaff_EBP + -0x3e))) {
        *(undefined4 *)(unaff_EBP + -0xa8) = 0;
      }
      else {
        *(undefined4 *)(unaff_EBP + -0xa8) = 1;
      }
      if (*(char *)(unaff_EBP + -0xa8) != '\0') {
        puVar10 = &DAT_006c08dc;
        puVar9 = &DAT_006c0c28;
        iVar2 = (int)*(char *)(unaff_EBP + -0x3e);
        pcVar8 = s_is_at_006c3c6c;
        pcVar7 = s_but_root_006c3c60;
        puVar6 = &DAT_006c0c28;
        iVar3 = (int)*(char *)(unaff_EBP + -0x3a);
        pcVar5 = s_is_at_006c3c6c;
        FUN_004442e5(&DAT_006fe545,*(undefined4 *)(unaff_EBP + -0x24),s_is_at_006c3c6c,iVar3,
                     &DAT_006c0c28,unaff_EBP + -0x3c,s_but_root_006c3c60,
                     *(undefined4 *)(unaff_EBP + -0x38),s_is_at_006c3c6c,iVar2,&DAT_006c0c28,
                     unaff_EBP + -0x40,&DAT_006c08dc);
        FUN_005bc69b(pcVar5);
        FUN_005bc69b(iVar3);
        uVar4 = FUN_005bc69b(puVar6);
        FUN_00444296(uVar4);
        uVar4 = FUN_005bc69b(pcVar7);
        FUN_004442e5(uVar4);
        FUN_005bc69b(pcVar8);
        FUN_005bc69b(iVar2);
        uVar4 = FUN_005bc69b(puVar9);
        FUN_00444296(uVar4);
        FUN_005bc69b(puVar10);
      }
      *(undefined1 *)(unaff_EBP + -4) = 2;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    uVar4 = *(undefined4 *)(*(int *)(unaff_EBP + -0x24) + 0xe0);
    *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return CONCAT31((int3)((uint)uVar4 >> 8),1);
}

