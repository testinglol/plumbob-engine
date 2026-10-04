
uint FUN_0042db93(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int extraout_ECX;
  uint uVar8;
  undefined2 uVar9;
  int unaff_EBP;
  undefined *puVar10;
  uint uStack_50;
  uint uStack_4c;
  int *piStack_48;
  uint uStack_44;
  
  FUN_00634c24();
  iVar5 = *DAT_006e486c;
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  piVar7 = *(int **)(*(int *)(iVar5 + 0x14) + 0x84);
  piVar4 = *(int **)(*(int *)(iVar5 + 0x14) + 0x88);
  do {
    if (piVar7 == piVar4) {
LAB_0042de8e:
      uVar8 = (uint)piVar4 & 0xffffff00;
LAB_0042de90:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar8;
    }
    if ((*piVar7 != 0) && (*(short *)(*piVar7 + 0xf0) == **(short **)(unaff_EBP + 8))) {
      piVar7 = (int *)*piVar7;
      if (piVar7 != (int *)0x0) {
        uStack_44 = 0x42dbf3;
        piVar4 = (int *)FUN_00445724();
        if (piVar7 == piVar4) {
          uStack_44 = 0;
          piStack_48 = (int *)0x42dc04;
          piVar4 = (int *)FUN_00445489();
        }
        uVar8 = (uint)*(short *)((int)piVar7 + 0x5ca);
        if (((int)uVar8 < 1) ||
           (piVar4 = (int *)(extraout_ECX + 0x148),
           (uint)(*(int *)(extraout_ECX + 0x14c) - *piVar4 >> 2) < uVar8)) {
          iVar5 = 0;
        }
        else {
          piVar4 = (int *)*piVar4;
          iVar5 = piVar4[uVar8 - 1];
        }
        iVar2 = *(int *)(iVar5 + 8);
        *(int *)(unaff_EBP + -0x20) = iVar2;
        if ((iVar2 != 0) && (iVar5 != 0)) {
          *(int *)(unaff_EBP + -0x1c) = (int)(short)piVar7[0x181];
          *(int *)(unaff_EBP + -0x18) = (int)*(short *)((int)piVar7 + 0x62e);
          *(int *)(unaff_EBP + -0x14) = (int)(short)piVar7[0x18b];
          *(int *)(unaff_EBP + -0x34) = piVar7[0x3d];
          sVar1 = *(short *)((int)piVar7 + 0x60e);
          *(int *)(unaff_EBP + -0x30) = piVar7[0x3e];
          *(int *)(unaff_EBP + -0x2c) = piVar7[0x44];
          *(short *)(unaff_EBP + -0x28) = (short)piVar7[0x13];
          uStack_44 = 0x42dc92;
          uStack_44 = FUN_0045741b();
          piStack_48 = (int *)0x42dc98;
          uVar8 = FUN_004e988f();
          piStack_48 = (int *)0x0;
          uStack_50 = 0x42dca3;
          uStack_4c = uVar8;
          FUN_004ea53c();
          uStack_50 = (int)sVar1 & 1;
          FUN_004eabf6(uVar8);
          iVar5 = *(int *)(unaff_EBP + -0x1c);
          if (iVar5 == 1) {
            *(uint **)(unaff_EBP + -0x1c) = &uStack_50;
            puVar10 = &DAT_006c1010;
LAB_0042dce7:
            FUN_0040bfed(puVar10);
            FUN_004eac8c(uVar8);
          }
          else {
            if (iVar5 == 2) {
              *(uint **)(unaff_EBP + -0x1c) = &uStack_50;
              puVar10 = &DAT_006c1008;
              goto LAB_0042dce7;
            }
            if (iVar5 == 3) {
              *(uint **)(unaff_EBP + -0x1c) = &uStack_50;
              puVar10 = &DAT_006c100c;
              goto LAB_0042dce7;
            }
          }
          piStack_48 = (int *)0x42dcfb;
          uStack_44 = uVar8;
          iVar5 = FUN_004ea79e();
          uVar9 = (undefined2)*(undefined4 *)(unaff_EBP + -0x18);
          *(undefined2 *)(iVar5 + 0xa2) = uVar9;
          uStack_4c = 0x42dd0b;
          piStack_48 = (int *)uVar8;
          iVar5 = FUN_004ea79e();
          *(undefined2 *)(iVar5 + 0xa4) = uVar9;
          uStack_50 = 0x42dd18;
          uStack_4c = uVar8;
          iVar5 = FUN_004ea79e();
          uStack_50 = 0;
          *(undefined2 *)(iVar5 + 0xa0) = *(undefined2 *)(unaff_EBP + -0x14);
          FUN_004eaa9b(uVar8);
          uVar6 = FUN_004eacb7(uVar8);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
          uVar6 = FUN_004ead68(uVar8);
          *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0;
          if (0 < *(int *)(unaff_EBP + -0x10)) {
            uStack_44 = *(undefined4 *)(unaff_EBP + -0x10);
            piStack_48 = (int *)0x42dd59;
            uVar6 = FUN_005bc722();
            *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
          }
          if (0 < *(int *)(unaff_EBP + -0x14)) {
            uStack_44 = *(undefined4 *)(unaff_EBP + -0x14);
            piStack_48 = (int *)0x42dd6b;
            uVar6 = FUN_005bc722();
            *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
          }
          uStack_44 = *(undefined4 *)(unaff_EBP + -0x18);
          uStack_4c = 0x42dd77;
          piStack_48 = (int *)uVar8;
          FUN_004eacf0();
          uStack_4c = *(undefined4 *)(unaff_EBP + -0x1c);
          uStack_50 = uVar8;
          FUN_004eada1();
          FUN_004eadc1(uVar8);
          iVar5 = FUN_004ea79e(uVar8);
          *(undefined2 *)(iVar5 + 0x14) = 0;
          iVar5 = FUN_004ea79e(uVar8);
          *(undefined2 *)(iVar5 + 0x16) = 0;
          iVar5 = FUN_004ea79e(uVar8);
          *(undefined2 *)(iVar5 + 0x18) = 0;
          iVar5 = FUN_004ea79e(uVar8);
          *(undefined2 *)(iVar5 + 0x1e) = 0;
          iVar5 = FUN_004ea79e(uVar8);
          *(undefined2 *)(iVar5 + 0x22) = 0;
          iVar5 = FUN_004ea79e(uVar8);
          *(undefined2 *)(iVar5 + 0x24) = 0;
          iVar5 = FUN_004ea79e(uVar8);
          *(undefined2 *)(iVar5 + 0x70) = 0;
          iVar5 = FUN_004ea79e(uVar8);
          *(undefined2 *)(iVar5 + 0x72) = 0;
          uStack_44 = 0x42dde1;
          thunk_FUN_00457ea7();
          uStack_44 = 0x42dde8;
          uStack_44 = FUN_004096c2();
          piStack_48 = (int *)0x42ddf1;
          FUN_005b870f();
          uStack_44 = unaff_EBP + -0x40;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          uStack_4c = 0x42ddfe;
          piStack_48 = (int *)uVar8;
          FUN_004e9a99();
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          uStack_44 = 0x42de0c;
          FUN_005b8770();
          uStack_44 = 0;
          piStack_48 = (int *)0x0;
          uStack_4c = 1;
          uStack_50 = uVar8;
          FUN_004ea674();
          uStack_44 = 0x42de21;
          uStack_44 = FUN_0045741b();
          piStack_48 = (int *)0x42de27;
          FUN_0042dea1();
          uStack_4c = 0x42de2d;
          piStack_48 = (int *)uVar8;
          piVar7 = (int *)FUN_004e9744();
          piVar4 = (int *)0x0;
          if (piVar7 != (int *)0x0) {
            uStack_44 = DAT_006e4f10 + 0x84;
            uStack_4c = 0x42de49;
            piStack_48 = piVar7;
            FUN_004258ed();
            *(byte *)((int)piVar7 + 0x115) = *(byte *)((int)piVar7 + 0x115) | 0x10;
            uStack_44 = 0;
            piStack_48 = (int *)0x42de58;
            (**(code **)(*piVar7 + 0x38))();
            uStack_4c = (uint)*(short *)(unaff_EBP + -0x28);
            piStack_48 = (int *)0x0;
            uStack_50 = 1;
            FUN_004550e0(*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30),
                         *(undefined4 *)(unaff_EBP + -0x2c),0,0);
            iVar5 = piVar7[0x3c];
            **(short **)(unaff_EBP + 0xc) = (short)iVar5;
            psVar3 = *(short **)(unaff_EBP + 8);
            if (*psVar3 != (short)iVar5) {
              *psVar3 = 0;
            }
            uVar8 = CONCAT31((int3)((uint)psVar3 >> 8),1);
            goto LAB_0042de90;
          }
        }
      }
      goto LAB_0042de8e;
    }
    piVar7 = piVar7 + 1;
  } while( true );
}

