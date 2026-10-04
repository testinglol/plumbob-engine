
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a90a0(void)

{
  int iVar1;
  char cVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  undefined2 *puVar6;
  int iVar7;
  int iStack_14;
  int iStack_10;
  int *piStack_c;
  int *piStack_8;
  
  do {
    cVar3 = *(char *)((int)unaff_ESI + 0x17f);
    cVar2 = (char)unaff_EBX;
    *(undefined4 *)(unaff_EBP + -4) = 6;
    if (cVar3 != cVar2) {
      piVar4 = (int *)FUN_005cf113();
      iVar7 = *piVar4;
      *(int **)(unaff_EBP + -0x1c) = piVar4;
      for (; iVar7 != piVar4[1]; iVar7 = iVar7 + 0x10) {
        piStack_8 = *(int **)(unaff_EBP + -0x14);
        piStack_c = (int *)0xff;
        iStack_14 = 0x4a90d4;
        iStack_10 = iVar7;
        FUN_004b06db();
        piVar4 = *(int **)(unaff_EBP + -0x1c);
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    piStack_8 = (int *)0x4a90f5;
    FUN_004b048c();
    cVar3 = FUN_004b465e();
    if (cVar3 != '\0') {
      if (DAT_006e4870 != cVar2) {
        FUN_005cf10c();
        FUN_004a891e();
        piVar4 = (int *)FUN_005cf113();
        *(int **)(unaff_EBP + -0x1c) = piVar4;
        if (piVar4 != unaff_ESI + 0x22) {
          piStack_8 = (int *)0x4a9135;
          FUN_004b4251();
          iVar7 = *(int *)(unaff_EBP + -0x1c);
          *(char *)(iVar7 + 0xc) = (char)unaff_ESI[0x25];
          *(int *)(iVar7 + 0x10) = unaff_ESI[0x26];
        }
        FUN_005caf36();
        piStack_8 = (int *)0x4a9155;
        FUN_005cf113();
        piStack_8 = (int *)0x4a915c;
        FUN_005cdecb();
      }
      FUN_004a891e();
    }
    piStack_8 = (int *)s_Rest_of_UI_006c7290;
    *(char *)((int)unaff_ESI + 0x179) = cVar2;
    piStack_c = (int *)0x4a917b;
    FUN_005d51f5();
    piStack_8 = (int *)0x4a9186;
    FUN_004b406a();
    if (((char)unaff_ESI[0x137] != cVar2) && (cVar3 = FUN_004b465e(), cVar3 != '\0')) {
      iVar7 = 100;
      *(char *)(unaff_ESI + 0x137) = cVar2;
      piStack_8 = (int *)0x4a91b1;
      piVar4 = operator_new(100);
      *(int **)(unaff_EBP + -0x1c) = piVar4;
      *(undefined4 *)(unaff_EBP + -4) = 8;
      if (piVar4 == unaff_EBX) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_005dfb13();
        iVar7 = extraout_ECX;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int **)(unaff_EBP + -0x18) = piVar4;
      *(int **)(unaff_EBP + -0x1c) = piVar4;
      if (piVar4 != unaff_EBX) {
        iVar1 = *piVar4;
        *(int **)(unaff_EBP + -0x20) = &iStack_14;
        piVar4 = unaff_ESI + 0x138;
        *(int *)(unaff_EBP + -0x20) = iVar1;
        iStack_14 = iVar7;
        iStack_10 = iVar7;
        piStack_c = unaff_EBX;
        piStack_8 = unaff_EBX;
        FUN_00436a50(4);
        uVar5 = FUN_004a946b();
        uVar5 = FUN_004a9465(uVar5);
        cVar3 = (**(code **)(*(int *)(unaff_EBP + -0x20) + 0xc))(uVar5);
        if (cVar3 != '\0') {
          if ((char)unaff_ESI[0x130] != '\0') {
            piStack_8 = (int *)unaff_ESI[0x1c];
            piStack_c = (int *)0x4a9231;
            FUN_004b038a();
            if ((char)unaff_ESI[0x1e] != '\0') {
              unaff_ESI[0x1f] = 0;
            }
            piStack_8 = (int *)0x4a9243;
            FUN_004b1779();
            piStack_8 = (int *)0x4a924d;
            FUN_004b048c();
          }
          piStack_8 = (int *)0x4a9257;
          cVar3 = (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x20))();
          iVar1 = DAT_006f0084;
          iVar7 = DAT_006f0080;
          if (cVar3 != '\0') {
            *piVar4 = *piVar4 + DAT_006f0080;
            unaff_ESI[0x13a] = unaff_ESI[0x13a] + iVar7;
            unaff_ESI[0x139] = unaff_ESI[0x139] + iVar1;
            unaff_ESI[0x13b] = unaff_ESI[0x13b] + iVar1;
            if (*piVar4 < 0) {
              iVar7 = -*piVar4;
              *piVar4 = *piVar4 + iVar7;
              unaff_ESI[0x13a] = unaff_ESI[0x13a] + iVar7;
            }
            if (unaff_ESI[0x139] < 0) {
              iVar7 = -unaff_ESI[0x139];
              unaff_ESI[0x139] = unaff_ESI[0x139] + iVar7;
              unaff_ESI[0x13b] = unaff_ESI[0x13b] + iVar7;
            }
            iVar7 = *(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x1c);
            if (iVar7 < unaff_ESI[0x13a]) {
              iVar7 = iVar7 - unaff_ESI[0x13a];
              *piVar4 = *piVar4 + iVar7;
              unaff_ESI[0x13a] = unaff_ESI[0x13a] + iVar7;
            }
            iVar7 = *(int *)(*(int *)(DAT_006e486c + 0x3c) + 0x20);
            if (iVar7 < unaff_ESI[0x13b]) {
              iVar7 = iVar7 - unaff_ESI[0x13b];
              unaff_ESI[0x139] = unaff_ESI[0x139] + iVar7;
              unaff_ESI[0x13b] = unaff_ESI[0x13b] + iVar7;
            }
            piStack_8 = *(int **)(unaff_EBP + -0x18) + 5;
            iStack_10 = *(int *)(DAT_006e486c + 0x3c);
            iStack_14 = 0x4a92e7;
            piStack_c = piVar4;
            (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x9c))();
            iStack_14 = 0x10;
            (**(code **)(**(int **)(unaff_EBP + -0x18) + 0x24))();
            cVar3 = FUN_004074bc();
            if (cVar3 == '\x01') {
LAB_004a933d:
              iVar7 = FUN_00410977();
              *(int *)(unaff_EBP + -0x20) = iVar7;
              if (iVar7 != 0) {
                FUN_004cfdf2();
                piStack_8 = *(int **)(unaff_EBP + -0x18);
                piStack_c = (int *)0x4a9365;
                FUN_004ed86c();
                iVar7 = unaff_ESI[0x13e];
                *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                if (iVar7 != unaff_ESI[0x13d]) {
                  piStack_8 = (int *)0x4a9382;
                  FUN_004ed980();
                  piStack_8 = (int *)0x0;
                  piStack_c = (int *)0x4a9390;
                  FUN_00406466();
                }
              }
            }
            else {
              FUN_004e99a9();
              piStack_8 = (int *)0x4a9319;
              iVar7 = FUN_004e9744();
              if (iVar7 != 0) {
                piStack_8 = (int *)0x4a9337;
                iVar7 = FUN_00425db3();
                if (iVar7 != 0) goto LAB_004a933d;
              }
            }
            if (((char)unaff_ESI[0x13c] != '\0') && (*(int *)(DAT_006f2a08 + 0x84) != 0)) {
              piStack_8 = (int *)0x0;
              piStack_c = (int *)0x1f;
              iStack_10 = 3;
              iStack_14 = *(int *)(DAT_006f2a08 + 0x84);
              FUN_005da644();
            }
          }
          if ((char)unaff_ESI[0x130] != '\0') {
            piStack_8 = (int *)unaff_ESI[0x1c];
            piStack_c = (int *)0x4a93ce;
            FUN_004b038a();
            if ((char)unaff_ESI[0x1e] != '\0') {
              unaff_ESI[0x1f] = 0;
            }
            piStack_8 = (int *)0x4a93e0;
            FUN_004b1779();
            piStack_8 = (int *)0x4a93ea;
            FUN_004b048c();
          }
        }
        unaff_EBX = (int *)0x0;
        if (*(undefined4 **)(unaff_EBP + -0x1c) != (undefined4 *)0x0) {
          piStack_8 = (int *)0x4a93fb;
          (**(code **)**(undefined4 **)(unaff_EBP + -0x1c))();
        }
      }
    }
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
    if (*(int *)(unaff_EBP + -0x30) <= *(int *)(unaff_EBP + -0x2c)) {
      piStack_8 = (int *)s_VitaBoy__UnloadManager_006c7278;
      piStack_c = (int *)0x4a9416;
      FUN_005d51f5();
      piStack_8 = (int *)0x4a941e;
      FUN_004b406a();
      thunk_FUN_005847fc();
      piStack_8 = (int *)0x4a9430;
      FUN_005a042b();
      piStack_8 = (int *)s_UW__End_006c7300;
      piStack_c = (int *)0x4a944c;
      FUN_005d51f5();
      piStack_8 = (int *)0x4a9454;
      FUN_004b406a();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    if (*(int *)(unaff_EBP + -0x28) == 1) {
      piStack_8 = (int *)0x7;
      *(undefined4 *)(unaff_EBP + -0x28) = 2;
      iStack_10 = 0x4a8e7a;
      piStack_c = unaff_EBX;
      FUN_004b463f();
      piStack_8 = (int *)0x8;
      iStack_10 = 0x4a8e86;
      piStack_c = unaff_EBX;
      FUN_004b463f();
    }
    cVar3 = (char)unaff_EBX;
    if (((int *)unaff_ESI[0x5c] == unaff_EBX) && ((int *)unaff_ESI[0x5d] == unaff_EBX)) {
      if (DAT_006e4870 != cVar3) {
        piStack_8 = (int *)s_Scrolling_on__but_didn_t_scroll_006c72c8;
        piStack_c = (int *)0x4a8eb7;
        FUN_005d51f5();
        piStack_8 = (int *)0x4a8ec2;
        FUN_004b406a();
      }
      if ((unaff_ESI[0x133] < unaff_ESI[0x135]) && (unaff_ESI[0x134] < unaff_ESI[0x136])) {
        FUN_004b469d();
        *(undefined4 *)(unaff_EBP + -0x38) = DAT_006fe838;
        DAT_006fe838 = DAT_006d6180;
        piStack_8 = (int *)0x4a8f02;
        FUN_005cddcf();
        DAT_006fe838 = *(undefined4 *)(unaff_EBP + -0x38);
        unaff_ESI[0x133] = (int)unaff_EBX;
        unaff_ESI[0x134] = (int)unaff_EBX;
        unaff_ESI[0x135] = (int)unaff_EBX;
        unaff_ESI[0x136] = (int)unaff_EBX;
      }
      cVar2 = FUN_004b465e();
      puVar6 = *(undefined2 **)(unaff_EBP + -0x24);
      if (cVar2 != '\0') {
        piStack_8 = (int *)0x4a8f30;
        FUN_004ab376();
      }
    }
    else {
      FUN_005db0b7();
      FUN_0057ac7f();
      FUN_004a7d36();
      piStack_8 = (int *)0x4a8f5f;
      iVar7 = FUN_00636bef();
      piVar4 = *(int **)(unaff_EBP + -0x24);
      if (iVar7 < piVar4[2] - *piVar4) {
        piStack_8 = (int *)0x4a8f77;
        iVar7 = FUN_00636bef();
        if (piVar4[3] - piVar4[1] <= iVar7) goto LAB_004a8fd6;
        *(uint *)(unaff_EBP + -0x1c) = (uint)(DAT_006e4870 == cVar3);
        cVar2 = FUN_004b465e();
        if (cVar2 != '\0') {
          FUN_004aadfa();
        }
        piStack_8 = (int *)0xf;
        iStack_10 = 0x4a8faf;
        piStack_c = unaff_EBX;
        FUN_004b463f();
        piStack_8 = (int *)0x8;
        iStack_10 = 0x4a8fbe;
        piStack_c = unaff_EBX;
        FUN_004b463f();
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + 1;
        *(undefined4 *)(unaff_EBP + -0x28) = 1;
        piStack_8 = *(int **)(unaff_EBP + -0x1c);
        piStack_c = *(int **)(unaff_EBP + -0x24);
        iStack_10 = 0x4a8fd4;
        FUN_004ab1fb();
      }
      else {
LAB_004a8fd6:
        (**(code **)(*unaff_ESI + 0x48))();
      }
      puVar6 = *(undefined2 **)(unaff_EBP + -0x24);
      unaff_ESI[0x5c] = (int)unaff_EBX;
      unaff_ESI[0x5d] = (int)unaff_EBX;
    }
    piStack_8 = (int *)(unaff_EBP + -0x40);
    iStack_10 = 0x4a8ffb;
    piStack_c = (int *)puVar6;
    FUN_004a9472();
    piStack_8 = (int *)s_UW__Censor_Cursor_Zooming_PopupH_006c729c;
    piStack_c = (int *)0x4a9009;
    FUN_005d51f5();
    piStack_8 = (int *)0x4a9014;
    FUN_004b406a();
    *(undefined2 *)(unaff_EBP + -0x50) = puVar6[2];
    *(undefined2 *)(unaff_EBP + -0x4c) = puVar6[6];
    *(undefined2 *)(unaff_EBP + -0x4e) = *puVar6;
    *(undefined2 *)(unaff_EBP + -0x4a) = puVar6[4];
    _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x4c);
    piStack_8 = (int *)unaff_ESI[0x1c];
    _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x50);
    *(undefined4 *)(unaff_EBP + -0x3c) = _DAT_006f0bc4;
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x50);
    piStack_c = (int *)0x4a9057;
    FUN_004b038a();
    if ((char)unaff_ESI[0x1e] != cVar3) {
      unaff_ESI[0x1f] = (int)unaff_EBX;
    }
    *(undefined4 *)(unaff_EBP + -4) = 1;
    piStack_8 = (int *)&DAT_006f0bc0;
    piStack_c = (int *)0x4a9076;
    FUN_004acdcb();
    piStack_8 = (int *)&DAT_006f0bc0;
    piStack_c = (int *)0x4a9081;
    FUN_004ac916();
    if ((int *)unaff_ESI[0x11f] != unaff_EBX) {
      piStack_8 = (int *)0x4a9093;
      FUN_004b0ba6();
      FUN_004a90a0();
      return;
    }
  } while( true );
}

