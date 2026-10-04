
void __fastcall FUN_00459c08(int param_1)

{
  int iVar1;
  int iVar2;
  short sVar3;
  short *psVar4;
  int local_18 [5];
  
  local_18[3] = 0;
  local_18[0] = 4;
  local_18[1] = 3;
  local_18[2] = 3;
  psVar4 = (short *)(param_1 + 0x5e8);
  local_18[4] = param_1;
  do {
    do {
      iVar1 = _rand();
      iVar1 = iVar1 % 3;
    } while (local_18[iVar1] < 1);
    local_18[iVar1] = local_18[iVar1] + -1;
    if (iVar1 == 0) {
      iVar1 = _rand();
      sVar3 = (short)(iVar1 % 4);
    }
    else if (iVar1 == 1) {
      iVar1 = _rand();
      sVar3 = (short)(iVar1 % 3) + 4;
    }
    else if (iVar1 == 2) {
      iVar1 = _rand();
      sVar3 = (short)(iVar1 % 4) + 7;
    }
    else {
      sVar3 = 10;
    }
    local_18[3] = local_18[3] + 1;
    *psVar4 = sVar3 * 100;
    psVar4 = psVar4 + 1;
  } while (local_18[3] < 10);
  local_18[0] = 1;
  local_18[1] = 2;
  local_18[2] = 2;
  iVar1 = 0;
  do {
    do {
      iVar2 = _rand();
      iVar2 = iVar2 % 3;
    } while (local_18[iVar2] < 1);
    local_18[iVar2] = local_18[iVar2] + -1;
    if (iVar2 == 0) {
      iVar2 = _rand();
      sVar3 = (short)(iVar2 % 4);
    }
    else if (iVar2 == 1) {
      iVar2 = _rand();
      sVar3 = (short)(iVar2 % 3) + 4;
    }
    else if (iVar2 == 2) {
      iVar2 = _rand();
      sVar3 = (short)(iVar2 % 4) + 7;
    }
    else {
      sVar3 = 10;
    }
    if (iVar1 == 0) {
      *(short *)(local_18[4] + 0x5a6) = sVar3 * 100;
    }
    else if (iVar1 == 1) {
      *(short *)(local_18[4] + 0x5a8) = sVar3 * 100;
    }
    else if (iVar1 == 2) {
      *(short *)(local_18[4] + 0x5ac) = sVar3 * 100;
    }
    else if (iVar1 == 3) {
      *(short *)(local_18[4] + 0x5b4) = sVar3 * 100;
    }
    else if (iVar1 == 4) {
      *(short *)(local_18[4] + 0x5c0) = sVar3 * 100;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 5);
  return;
}

