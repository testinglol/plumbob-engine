
void __fastcall FUN_0040a5ea(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *local_668;
  undefined1 local_660 [256];
  undefined **local_560;
  char *local_55c;
  undefined2 local_558;
  undefined1 local_554 [256];
  undefined **local_454;
  char *local_450;
  undefined2 local_44c;
  undefined1 local_448 [256];
  undefined **local_348;
  char *local_344;
  undefined2 local_340;
  undefined1 local_33c [256];
  undefined **local_23c;
  char *local_238;
  undefined1 local_230 [256];
  undefined **local_130;
  char *local_12c;
  undefined2 local_128;
  undefined1 local_124 [256];
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = param_1[2];
  local_20 = 0;
  local_24 = FUN_0040d106();
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_18 = 0;
  local_1c = 0;
  iVar1 = FUN_0040cd0e();
  if (-1 < iVar1) {
    if (iVar1 < 2) {
      local_20 = FUN_0040d46a();
      iVar1 = FUN_0040cc3f();
      if (iVar1 == 0) {
        local_14 = FUN_0040d591();
        local_10 = FUN_0040d8a9();
        local_c = FUN_0040dbc1();
        local_18 = FUN_0040ded9();
        local_1c = FUN_0040e1f1();
      }
      else {
        FUN_005876ac(0x1f,s_ADDED_006c0f8c);
        local_14 = 0;
        local_10 = FUN_0040d8a9();
        local_c = FUN_0040dbc1();
        local_18 = FUN_0040ded9();
        FUN_005876ac(0x23,s_ADDED_006c0f8c);
        local_1c = 0;
      }
    }
    else if (iVar1 < 6) {
      FUN_005876ac(3,&DAT_006c0fd4);
      FUN_005876ac(0x1f,&DAT_006c0fd4);
      FUN_005876ac(0x20,&DAT_006c0fd4);
      FUN_005876ac(0x21,&DAT_006c0fd4);
      FUN_005876ac(0x22,&DAT_006c0fd4);
      FUN_005876ac(0x23,&DAT_006c0fd4);
    }
  }
  if (local_24 != -1) {
    FUN_0046f824(local_230,0,0x100);
    local_23c = &PTR_FUN_00666524;
    FUN_0046f824(local_33c,0,0x100);
    local_348 = &PTR_FUN_00666524;
    uVar2 = FUN_004705f2(2,0xffffffff);
    FUN_0046f8cb(uVar2);
    local_340 = 0;
    *local_344 = '\0';
    FUN_0046f847(local_238 + 6,3);
    iVar1 = FUN_0040cd0e();
    if ((-1 < iVar1) && (iVar1 < 2)) {
      iVar1 = FUN_0040cc3f();
      if (iVar1 == 0) {
        iVar1 = _strcmp(local_344,(char *)&PTR_DAT_006c0fd0);
        if (iVar1 != 0) {
          iVar1 = _strcmp(local_344,&DAT_006c0fcc);
          if (iVar1 != 0) {
            iVar1 = _strcmp(local_344,&DAT_006c0fc8);
            if (iVar1 != 0) goto LAB_0040ab0d;
          }
        }
        FUN_0046f824(local_554,0,0x100);
        local_560 = &PTR_FUN_00666524;
        FUN_0046f824(local_660,0,0x100);
        FUN_0046f824(local_448,0,0x100);
        local_454 = &PTR_FUN_00666524;
        FUN_0046f824(local_124,0,0x100);
        local_130 = &PTR_FUN_00666524;
        uVar2 = FUN_004705f2(0x1f,0xffffffff);
        FUN_0046f8cb(uVar2);
        local_558 = 0;
        *local_55c = '\0';
        FUN_0046f847(local_238 + 6,3);
        uVar2 = FUN_004705f2(0x20,0xffffffff);
        FUN_0046f8cb(uVar2);
        *local_668 = '\0';
        FUN_0046f847(local_238 + 6,3);
        uVar2 = FUN_004705f2(0x21,0xffffffff);
        FUN_0046f8cb(uVar2);
        local_44c = 0;
        *local_450 = '\0';
        FUN_0046f847(local_238 + 6,3);
        uVar2 = FUN_004705f2(0x23,0xffffffff);
        FUN_0046f8cb(uVar2);
        local_128 = 0;
        *local_12c = '\0';
        FUN_0046f847(local_238 + 6,3);
        if (local_14 != -1) {
          iVar1 = _strcmp(local_344,local_55c);
          if (iVar1 != 0) {
            local_14 = -1;
          }
        }
        if (local_10 != -1) {
          iVar1 = _strcmp(local_344,local_668);
          if (iVar1 != 0) {
            local_10 = -1;
          }
        }
        if (local_c != -1) {
          iVar1 = _strcmp(local_344,local_450);
          if (iVar1 != 0) {
            local_c = -1;
          }
        }
        if (local_1c != -1) {
          iVar1 = _strcmp(local_344,local_12c);
          if (iVar1 != 0) {
            local_1c = -1;
          }
        }
      }
      else {
        iVar1 = _strcmp(local_344,(char *)&PTR_LAB_006c0fc4);
        if (iVar1 == 0) {
          FUN_0046f824(local_124,0,0x100);
          local_130 = &PTR_FUN_00666524;
          FUN_0046f824(local_448,0,0x100);
          local_454 = &PTR_FUN_00666524;
          uVar2 = FUN_004705f2(0x20,0xffffffff);
          FUN_0046f8cb(uVar2);
          local_128 = 0;
          *local_12c = '\0';
          FUN_0046f847(local_238 + 6,3);
          uVar2 = FUN_004705f2(0x21,0xffffffff);
          FUN_0046f8cb(uVar2);
          local_44c = 0;
          *local_450 = '\0';
          FUN_0046f847(local_238 + 6,3);
          if (local_10 != -1) {
            iVar1 = _strcmp(local_344,local_12c);
            if (iVar1 != 0) {
              local_10 = -1;
            }
          }
          if (local_c != -1) {
            iVar1 = _strcmp(local_344,local_450);
            if (iVar1 != 0) {
              local_c = -1;
            }
          }
        }
      }
LAB_0040ab0d:
      iVar1 = _strcmp(local_344,(char *)&PTR_DAT_006c0fd0);
      if (iVar1 != 0) {
        iVar1 = _strcmp(local_344,&DAT_006c0fcc);
        if (iVar1 != 0) {
          iVar1 = _strcmp(local_344,&DAT_006c0fc8);
          if (iVar1 != 0) {
            iVar1 = _strcmp(local_344,(char *)&PTR_LAB_006c0fc4);
            if (iVar1 != 0) goto LAB_0040abe1;
          }
        }
      }
      FUN_0046f824(local_124,0,0x100);
      local_130 = &PTR_FUN_00666524;
      uVar2 = FUN_004705f2(0x22,0xffffffff);
      FUN_0046f8cb(uVar2);
      local_128 = 0;
      *local_12c = '\0';
      FUN_0046f847(local_238 + 6,3);
      if (local_18 != -1) {
        iVar1 = _strcmp(local_344,local_12c);
        if (iVar1 != 0) {
          local_18 = -1;
        }
      }
    }
  }
LAB_0040abe1:
  if ((local_20 == -1) || (local_24 == -1)) {
    iVar1 = FUN_0040d43d();
    if (0 < iVar1) {
      iVar1 = FUN_0040d0d9();
      if (0 < iVar1) {
        FUN_0046f824(local_124,0,0x100);
        local_130 = &PTR_FUN_00666524;
        if (local_20 == -1) {
          FUN_00473047(&local_130);
          FUN_005876ac(3,local_12c);
        }
        if (local_24 == -1) {
          iVar1 = FUN_0040cd0e();
          if ((-1 < iVar1) && (iVar1 < 2)) {
            iVar1 = FUN_0040cc3f();
            if (iVar1 == 0) {
              local_14 = -1;
              local_10 = -1;
              local_c = -1;
              local_18 = -1;
              local_1c = -1;
            }
            else {
              local_10 = -1;
              local_c = -1;
              local_18 = -1;
            }
          }
          FUN_00473047(&local_130);
          FUN_005876ac(2,local_12c);
        }
        goto LAB_0040ad1e;
      }
    }
    FUN_005876ac(2,&DAT_006de560);
    FUN_005876ac(3,&DAT_006de560);
    FUN_005876ac(0x12,&DAT_006de560);
    FUN_005876ac(0x13,&DAT_006de560);
    FUN_005876ac(0x10,&DAT_006de560);
    FUN_005876ac(0x11,&DAT_006de560);
    FUN_004eae06(*param_1,0);
  }
LAB_0040ad1e:
  if (((local_14 != -1) && (local_10 != -1)) && (local_c != -1)) goto LAB_0040af26;
  iVar1 = FUN_0040d561();
  if (0 < iVar1) {
    iVar1 = FUN_0040d879();
    if (0 < iVar1) {
      iVar1 = FUN_0040db91();
      if (0 < iVar1) {
        iVar1 = FUN_0040cc3f();
        if (iVar1 == 0) {
          if (local_14 == -1) {
            if ((local_10 == -1) && (local_c == -1)) {
              FUN_0040b84f();
              goto LAB_0040af26;
            }
            local_14 = 0;
          }
          if (local_10 == -1) {
            local_10 = 0;
          }
          if (local_c == -1) {
            local_c = 0;
          }
          FUN_0046f824(local_230,0,0x100);
          local_23c = &PTR_FUN_00666524;
          FUN_00473047(&local_23c);
          FUN_005876ac(0x1f,local_238);
          FUN_00473047(&local_23c);
          FUN_005876ac(0x20,local_238);
          FUN_00473047(&local_23c);
        }
        else {
          if (local_14 == 0) {
            if (local_10 == -1) {
              if (local_c == -1) {
                FUN_0040c3d8();
                goto LAB_0040af26;
              }
LAB_0040ae76:
              local_10 = 0;
            }
          }
          else if (local_10 == -1) goto LAB_0040ae76;
          if (local_c == -1) {
            local_c = 0;
          }
          FUN_0046f824(local_124,0,0x100);
          local_130 = &PTR_FUN_00666524;
          FUN_00473047(&local_130);
          FUN_005876ac(0x20,local_12c);
          FUN_00473047(&local_130);
          local_238 = local_12c;
        }
        FUN_005876ac(0x21,local_238);
        goto LAB_0040af26;
      }
    }
  }
  FUN_005876ac(0x1f,&DAT_006de560);
  FUN_005876ac(0x20,&DAT_006de560);
  FUN_005876ac(0x21,&DAT_006de560);
  FUN_004eae06(*param_1,0);
LAB_0040af26:
  if (local_18 == -1) {
    iVar1 = FUN_0040dea9();
    if (iVar1 < 1) {
      FUN_005876ac(0x22,&DAT_006de560);
      FUN_004eae06(*param_1,0);
    }
    else {
      FUN_0040c8b7();
    }
  }
  if (local_1c == -1) {
    iVar1 = FUN_0040e1c1();
    if (iVar1 < 1) {
      FUN_005876ac(0x23,&DAT_006de560);
      FUN_004eae06(*param_1,0);
    }
    else {
      FUN_0040c04d();
    }
  }
  iVar1 = FUN_0040cd0e();
  if (-1 < iVar1) {
    if (iVar1 < 2) {
      FUN_0040afbd();
    }
    else if (iVar1 < 6) {
      FUN_004eae06(*param_1,param_1[1]);
    }
  }
  return;
}

