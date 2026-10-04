
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __thiscall FUN_00452c85(int param_1,undefined2 *param_2)

{
  char cVar1;
  float fVar2;
  char cVar3;
  ushort *puVar4;
  ushort uVar5;
  ushort uVar6;
  undefined2 uVar7;
  bool bVar8;
  undefined4 local_5c;
  int aiStack_58 [19];
  float *local_c;
  ushort *local_8;
  
  local_8 = (ushort *)0x0;
  local_c = (float *)0x0;
  cVar1 = (&DAT_00667244)[*(char *)((int)param_2 + 5)];
  uVar5 = FUN_00453181((short)*(char *)((int)param_2 + 7),param_2[1],0);
  *(ushort ***)(param_1 + 0x128) = &local_8;
  *(float ***)(param_1 + 300) = &local_c;
  uVar7 = (undefined2)((uint)&local_c >> 0x10);
  uVar6 = FUN_00453181(CONCAT22(uVar7,(short)*(char *)(param_2 + 3)),CONCAT22(uVar7,*param_2),cVar1)
  ;
  puVar4 = local_8;
  cVar3 = (char)uVar5;
  switch(*(undefined1 *)((int)param_2 + 5)) {
  case 0:
    goto code_r0x00452d07;
  case 1:
    goto code_r0x00452e82;
  case 2:
    bVar8 = uVar6 == uVar5;
    goto code_r0x00452d41;
  case 3:
    if (local_8 == (ushort *)0x0) {
      if (local_c == (float *)0x0) {
        aiStack_58[10] = 0x13;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(aiStack_58 + 10,&DAT_00698f30);
      }
      fVar2 = (float)(int)(short)uVar5 + *local_c;
code_r0x00452ee3:
      *local_c = fVar2;
    }
    else {
      *local_8 = *local_8 + uVar5;
    }
    break;
  case 4:
    if (local_8 == (ushort *)0x0) {
      if (local_c == (float *)0x0) {
        aiStack_58[9] = 0x13;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(aiStack_58 + 9,&DAT_00698f30);
      }
      fVar2 = *local_c - (float)(int)(short)uVar5;
      goto code_r0x00452ee3;
    }
    *local_8 = *local_8 - uVar5;
    break;
  case 5:
    if (local_8 == (ushort *)0x0) {
      if (local_c == (float *)0x0) {
        aiStack_58[0xb] = 0x13;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(aiStack_58 + 0xb,&DAT_00698f30);
      }
      fVar2 = (float)(int)(short)uVar5;
      goto code_r0x00452ee3;
    }
    *local_8 = uVar5;
    break;
  case 6:
    if (local_8 == (ushort *)0x0) {
      if (local_c == (float *)0x0) {
        aiStack_58[8] = 0x13;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(aiStack_58 + 8,&DAT_00698f30);
      }
      fVar2 = (float)(int)(short)uVar5 * *local_c;
      goto code_r0x00452ee3;
    }
    *local_8 = *local_8 * uVar5;
    break;
  case 7:
    if (uVar5 == 0) {
      aiStack_58[7] = 0x26;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 7,&DAT_00698f30);
    }
    if (local_8 == (ushort *)0x0) {
      if (local_c == (float *)0x0) {
        aiStack_58[6] = 0x13;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(aiStack_58 + 6,&DAT_00698f30);
      }
      fVar2 = *local_c / (float)(int)(short)uVar5;
      goto code_r0x00452ee3;
    }
    *local_8 = (short)*local_8 / (short)uVar5;
    break;
  case 8:
    if (0x10 < uVar5) {
      aiStack_58[1] = 0xd;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 1,&DAT_00698f30);
    }
    bVar8 = (1 << (cVar3 - 1U & 0x1f) & (int)(short)uVar6) != 0;
    goto code_r0x00452d41;
  case 9:
    if (0x10 < uVar5) {
      aiStack_58[5] = 0xd;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 5,&DAT_00698f30);
    }
    if (local_8 == (ushort *)0x0) {
      aiStack_58[4] = 0x13;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 4,&DAT_00698f30);
    }
    bVar8 = true;
    *local_8 = *local_8 | (ushort)(1 << (cVar3 - 1U & 0x1f));
    goto code_r0x00452d41;
  case 10:
    if (0x10 < uVar5) {
      aiStack_58[3] = 0xd;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 3,&DAT_00698f30);
    }
    if (local_8 == (ushort *)0x0) {
      aiStack_58[2] = 0x13;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 2,&DAT_00698f30);
    }
    bVar8 = true;
    *local_8 = *local_8 & ~(ushort)(1 << (cVar3 - 1U & 0x1f));
    goto code_r0x00452d41;
  case 0xb:
    if (local_8 == (ushort *)0x0) {
      if (local_c == (float *)0x0) {
        aiStack_58[0xc] = 0x13;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(aiStack_58 + 0xc,&DAT_00698f30);
      }
      *local_c = *local_c + _DAT_00666748;
    }
    else {
      *local_8 = *local_8 + 1;
    }
    uVar6 = *local_8;
    goto code_r0x00452e82;
  case 0xc:
    if (local_8 == (ushort *)0x0) {
      aiStack_58[0xe] = 0x13;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 0xe,&DAT_00698f30);
    }
    if (uVar5 == 0) {
      aiStack_58[0xd] = 0x26;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 0xd,&DAT_00698f30);
    }
    if ((short)*local_8 < 0) {
      *local_8 = -*local_8;
    }
    if ((short)uVar5 < 0) {
      uVar5 = -uVar5;
    }
    *local_8 = (short)*local_8 % (short)uVar5;
    break;
  case 0xd:
    if (local_8 == (ushort *)0x0) {
      aiStack_58[0x11] = 0x13;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 0x11,&DAT_00698f30);
    }
    *local_8 = *local_8 & uVar5;
    break;
  case 0xe:
    bVar8 = (short)uVar5 <= (short)uVar6;
    goto code_r0x00452d41;
  case 0xf:
    bVar8 = (short)uVar6 <= (short)uVar5;
    goto code_r0x00452d41;
  case 0x10:
    bVar8 = uVar6 != uVar5;
    goto code_r0x00452d41;
  case 0x11:
    if (local_8 == (ushort *)0x0) {
      if (local_c == (float *)0x0) {
        aiStack_58[0x12] = 0x13;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(aiStack_58 + 0x12,&DAT_00698f30);
      }
      *local_c = *local_c - _DAT_00666748;
    }
    else {
      *local_8 = *local_8 - 1;
    }
    uVar6 = *local_8;
    goto code_r0x00452d07;
  case 0x12:
    if (local_8 == (ushort *)0x0) {
      aiStack_58[0x10] = 0x13;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 0x10,&DAT_00698f30);
    }
    *local_8 = *local_8 | uVar5;
    break;
  case 0x13:
    if (local_8 == (ushort *)0x0) {
      aiStack_58[0xf] = 0x13;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58 + 0xf,&DAT_00698f30);
    }
    *local_8 = *local_8 ^ uVar5;
    break;
  case 0x14:
    if (local_8 == (ushort *)0x0) {
      aiStack_58[0] = 0x13;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(aiStack_58,&DAT_00698f30);
    }
    aiStack_58[0] = (int)(short)uVar5;
    uVar6 = __ftol();
    *puVar4 = uVar6;
    break;
  default:
    local_5c = 1;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_5c,&DAT_00698f30);
  }
  bVar8 = true;
code_r0x00452d41:
  if (((((cVar1 != '\0') && (cVar1 = *(char *)(param_2 + 3), '\r' < cVar1)) &&
       ((cVar1 < '\x10' || (cVar1 == '\x11')))) && (local_c != (float *)0x0)) &&
     ((fVar2 = _DAT_00666a60, *local_c < _DAT_00666a60 ||
      (fVar2 = _DAT_0066674c, _DAT_0066674c < *local_c)))) {
    *local_c = fVar2;
  }
  return bVar8;
code_r0x00452e82:
  bVar8 = (short)uVar6 < (short)uVar5;
  goto code_r0x00452d41;
code_r0x00452d07:
  bVar8 = (short)uVar5 < (short)uVar6;
  goto code_r0x00452d41;
}

