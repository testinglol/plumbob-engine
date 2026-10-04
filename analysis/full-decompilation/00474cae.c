
uint __thiscall FUN_00474cae(int *param_1,ushort *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  ushort *puVar7;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int *piVar8;
  undefined2 *puVar9;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar7 = param_2;
  if (*(int *)(param_2 + 6) == 0) {
    if ((int)(param_1[5] - param_1[4] & 0xfffffffcU) < 8) {
      param_2 = (ushort *)0x3e9;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_2,&DAT_00698f30);
    }
    FUN_00475463();
    (**(code **)(*param_1 + 8))();
  }
  else {
    uVar2 = *param_2;
    if ((uVar2 != 0xffff) && ((uVar2 & 0x8000) != 0)) {
      iVar6 = *param_1;
      puVar9 = (undefined2 *)0x0;
LAB_00474d0f:
      uVar4 = (**(code **)(iVar6 + 0xc))(puVar7,puVar9);
      return uVar4;
    }
    uVar3 = param_2[1];
    if (((short)uVar3 < 0) || (0xfa < (short)uVar3)) {
      param_2 = (ushort *)(int)(short)uVar3;
      if (param_2 == (ushort *)0xfd) {
        local_1c = 0x44c;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&local_1c,&DAT_00698f30);
      }
      if (((int)param_2 < 0xfe) || (0xff < (int)param_2)) {
        local_18 = 0x44c;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&local_18,&DAT_00698f30);
      }
      if ((int)(param_1[5] - param_1[4] & 0xfffffffcU) < 8) {
        local_8 = 0x3e9;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&local_8,&DAT_00698f30);
      }
      FUN_00475463();
      (**(code **)(*param_1 + 8))();
      puVar7 = (ushort *)FUN_004750a6();
      if (param_2 == (ushort *)0xfe) {
        *(undefined1 *)(param_1 + 8) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 8) = 0;
      }
      if (*(int *)(puVar7 + 4) == 0) {
        if (*puVar7 == 0xffff) {
          uVar4 = 0xffffffff;
        }
        else {
          uVar4 = *puVar7 & 0x7fff;
        }
        iVar6 = FUN_004020a6(uVar4,CONCAT22(extraout_var_00,puVar7[1]));
        if (iVar6 == 0) {
          local_c = 0x44e;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(&local_c,&DAT_00698f30);
        }
        if (param_2 == (ushort *)0xfe) {
          if (*(byte *)(iVar6 + 2) == 0xfd) {
            local_10 = 0x44c;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&local_10,&DAT_00698f30);
          }
          puVar7[1] = (ushort)*(byte *)(iVar6 + 2);
          bVar1 = *(byte *)(iVar6 + 2);
        }
        else {
          if (*(byte *)(iVar6 + 3) == 0xfd) {
            local_14 = 0x44c;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&local_14,&DAT_00698f30);
          }
          puVar7[1] = (ushort)*(byte *)(iVar6 + 3);
          bVar1 = *(byte *)(iVar6 + 3);
        }
        param_1[7] = (uint)bVar1;
      }
    }
    else {
      if (uVar2 == 0xffff) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = uVar2 & 0x7fff;
      }
      puVar9 = (undefined2 *)FUN_004020a6(uVar4,uVar3);
      if (puVar9 == (undefined2 *)0x0) {
        param_2 = (ushort *)0x44e;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&param_2,&DAT_00698f30);
      }
      if ((*(byte *)((int)puVar9 + 1) & 0x80) != 0) {
        iVar6 = *param_1;
        goto LAB_00474d0f;
      }
      param_1[1] = param_1[1] + 1;
      if (DAT_006c4d60 <= param_1[1]) {
        param_2 = (ushort *)0x44d;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(&param_2,&DAT_00698f30);
      }
      uVar4 = CONCAT22(extraout_var,*puVar9) & 0xffff7fff;
      if ((ushort)uVar4 < 0x100) {
        iVar6 = (**(code **)*param_1)(puVar7,puVar9);
        if (iVar6 == -1) {
          return 2;
        }
        if (iVar6 == 0) {
          if (*(byte *)((int)puVar9 + 3) == 0xfd) {
            local_8 = 0x44c;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&local_8,&DAT_00698f30);
          }
          puVar7[1] = (ushort)*(byte *)((int)puVar9 + 3);
          bVar1 = *(byte *)((int)puVar9 + 3);
          *(undefined1 *)(param_1 + 8) = 0;
          param_1[7] = (uint)bVar1;
        }
        else {
          if (iVar6 != 1) {
            if (iVar6 == 2) {
              return 1;
            }
            return -(uint)(iVar6 != 3) & 2;
          }
          if (*(byte *)(puVar9 + 1) == 0xfd) {
            param_2 = (ushort *)0x44c;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          puVar7[1] = (ushort)*(byte *)(puVar9 + 1);
          param_1[7] = (uint)*(byte *)(puVar9 + 1);
          *(undefined1 *)(param_1 + 8) = 1;
        }
        puVar7[4] = 0;
        puVar7[5] = 0;
      }
      else {
        if ((*(int *)(puVar9 + 2) != -1) || (piVar8 = (int *)0x0, *(int *)(puVar9 + 4) != -1)) {
          piVar8 = (int *)(puVar9 + 2);
        }
        uVar5 = FUN_004749b7(0,piVar8,uVar4);
        if ((char)uVar5 == '\0') {
          iVar6 = FUN_0040204f(CONCAT22((short)((uint)uVar5 >> 0x10),*puVar9) & 0xffff7fff);
          if (iVar6 != 0) {
            param_2 = (ushort *)0x3e8;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&param_2,&DAT_00698f30);
          }
          param_2 = (ushort *)0x44e;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(&param_2,&DAT_00698f30);
        }
      }
    }
  }
  return 0;
}

