/*
 * sysinfo.h: structure and entry points for sysinfo support
 *
 * Copyright (C) 2010-2011 Red Hat, Inc.
 * Copyright (C) 2010 Daniel Veillard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 * Author: Daniel Veillard <veillard@redhat.com>
 */

#ifndef __VIR_SYSINFOS_H__
# define __VIR_SYSINFOS_H__

# include "internal.h"
# include "util.h"

enum virSysinfoType {
    VIR_SYSINFO_SMBIOS,

    VIR_SYSINFO_LAST
};

typedef struct _virProcessorinfoDef virProcessorinfoDef;
typedef virProcessorinfoDef *virProcessorinfoDefPtr;
struct _virProcessorinfoDef {
    char *processor_socket_destination;
    char *processor_type;
    char *processor_family;
    char *processor_manufacturer;
    char *processor_signature;
    char *processor_version;
    char *processor_external_clock;
    char *processor_max_speed;
    char *processor_status;
    char *processor_serial_number;
    char *processor_part_number;
};

typedef struct _virMemoryDeviceinfoDef virMemoryDeviceinfoDef;
typedef virMemoryDeviceinfoDef *virMemoryDeviceinfoDefPtr;
struct _virMemoryDeviceinfoDef {
    char *memory_size;
    char *memory_form_factor;
    char *memory_locator;
    char *memory_bank_locator;
    char *memory_type;
    char *memory_type_detail;
    char *memory_speed;
    char *memory_manufacturer;
    char *memory_serial_number;
    char *memory_part_number;
};

typedef struct _virSysinfoDef virSysinfoDef;
typedef virSysinfoDef *virSysinfoDefPtr;
struct _virSysinfoDef {
    int type;

    char *bios_vendor;
    char *bios_version;
    char *bios_date;
    char *bios_release;

    char *system_manufacturer;
    char *system_product;
    char *system_version;
    char *system_serial;
    char *system_uuid;
    char *system_sku;
    char *system_family;

    size_t nprocessor;
    virProcessorinfoDefPtr processor;

    size_t nmemory;
    virMemoryDeviceinfoDefPtr memory;
};

virSysinfoDefPtr virSysinfoRead(void);

void virSysinfoDefFree(virSysinfoDefPtr def);

char *virSysinfoFormat(virSysinfoDefPtr def, const char *prefix)
    ATTRIBUTE_NONNULL(1) ATTRIBUTE_NONNULL(2);

bool virSysinfoIsEqual(virSysinfoDefPtr src,
                       virSysinfoDefPtr dst);

VIR_ENUM_DECL(virSysinfo)

#endif /* __VIR_SYSINFOS_H__ */
